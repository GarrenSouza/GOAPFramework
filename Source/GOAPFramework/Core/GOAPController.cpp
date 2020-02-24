// Fill out your copyright notice in the Description page of Project Settings.

#include "GOAPController.h"
#include "GOAPCharacter.h"
#include "GOAP.h"
#include "AStar.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#ifndef DEFAULT_ACTION_VALUE
#define DEFAULT_ACTION_VALUE 0
#endif

#ifndef PLANSTATECHANGED_BBKEY
#define PLANSTATECHANGED_BBKEY "PlanStateChanged"
#endif

#ifndef PLANCOST_BBKEY 
#define PLANCOST_BBKEY "ActualPlanCost"
#endif

#ifndef CURRENTGOAL_BB_KEY
#define CURRENTGOAL_BB_KEY "CurrentGoal"
#endif

AGOAPController::AGOAPController(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
	GOAPPlanner.goap_actionplanner_clear(&ActionPlanner);
	GOAPPlanner.goap_worldstate_clear(&ActualWorldState);
	GOAPPlanner.goap_worldstate_clear(&DesiredWorldState);
	bWantsPlayerState = true;										//The character gets an ID
}

void AGOAPController::DestroyControlledCharacter()
{
	APawn* ControlledPawn = K2_GetPawn();
	ControlledPawn->K2_DestroyActor();
	ControlledPawn = NULL;
}

void AGOAPController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	AGOAPCharacter* GOAPCharacter = Cast<AGOAPCharacter>(InPawn);	

	if (GOAPCharacter)
	{
		GOAPCharacter->InitializeEntity();

		if (GOAPCharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*GOAPCharacter->BehaviorTree->BlackboardAsset);
			ActionNames = &(GOAPCharacter->ActionNames);
			ImportantAtoms = &(GOAPCharacter->ImportantAtoms);
			actual_goal_map_key = &(GOAPCharacter->actual_goal_map_key);
			last_goal_map_key = &(GOAPCharacter->last_goal_map_key);
			Goals = &(GOAPCharacter->Goals);
			Logger = &(GOAPCharacter->Logger);

			BehaviorComp->StartTree(*GOAPCharacter->BehaviorTree);
			GOAPCharacter->InitializeActions();
			GOAPCharacter->InitializeActionsCosts();
			GOAPCharacter->InitializeImportantAtoms();
			GOAPCharacter->InitializeGoals();
			AGOAPController::GetActualWorldstate(&ActualWorldState);
			AGOAPController::SetDesiredWorldstate(&DesiredWorldState);
		}
	}
}

void AGOAPController::UnPossess()
{
	if (BehaviorComp && BehaviorComp->IsActive())
	{
		BehaviorComp->StopLogic(TEXT("This Character is not attached to a GOAPController anymore!"));
		BehaviorComp->StopTree();
	}
}

bool AGOAPController::GetNewPlan()
{
	//Logger->send_to_Output_logger(FString(TEXT("Working on a new plan!")), log_categories::WARNING);

	Logger->send_to_GamePreviewLogger(FString(TEXT("Working on a new plan!")), log_categories::WARNING, 3.0f);

	char desc[4096];													//Description buffer, for debug purposes
	const char* Plan[16];												//Plan container
	int32 PlanSize = 16;												//Max size of a plan
	GOAP::worldstate_t States[16];										//Container for the stages of the plan

	BlackboardComp->SetValueAsName(FName(TEXT(CURRENTGOAL_BB_KEY)), *actual_goal_map_key);
	
	GOAPPlanner.goap_description(&ActionPlanner, desc, sizeof(desc));	
	AGOAPController::GetActualWorldstate(&ActualWorldState);			//Update world perspective of the planner
	AGOAPController::SetDesiredWorldstate(&DesiredWorldState);			//Update the goal
	int32 PlanCost = AStarPlanner.astar_plan(&ActionPlanner, ActualWorldState, DesiredWorldState, Plan, States, &PlanSize);													//Custo do plano

	FName BBPlanStateChanged = FName(TEXT(PLANSTATECHANGED_BBKEY));
	AGOAPController::SetAtomState(&BBPlanStateChanged, false);				//Control flag within the Blackboard Component

	if (PlanCost != -1)
	{
		GOAPPlanner.goap_worldstate_description(&ActionPlanner, &ActualWorldState, desc, sizeof(desc));	//for debug
		AGOAPController::ResetActionValues();
		GOAPPlanner.goap_worldstate_description(&ActionPlanner, &ActualWorldState, desc, sizeof(desc));	//for debug
		int ActionUtility = PlanSize;											//Actions counter of the actual plan
		AGOAPController::ResetActionValues();
		for (int32 i = 0; ((i < PlanSize) && (i < 16)); i++)
		{
			FName ActionName = Plan[i];							//Next step of the plan
			if (AGOAPController::GetActionValue(&ActionName) == 0)	// Avoid the superposition of utility values of a action called twice (or more) during  a plan
			{
				AGOAPController::SetActionValue(&ActionName, ActionUtility--);	//Every Action receive an utility value
				continue;
			}
			break;
		}
		FName BBPlanCostKey = FName(TEXT(PLANCOST_BBKEY));
		AGOAPController::SetActualPlanCost(&BBPlanCostKey, PlanCost);
		//Logger->send_to_Output_logger(FString(TEXT("Done! Gota new plan!")), log_categories::WARNING);
		Logger->send_to_GamePreviewLogger(FString(TEXT("Done! Got a new plan!")), log_categories::WARNING, 3.0f);
		return true;
	}
	//Logger->send_to_Output_logger(FString(TEXT("Oh damn it! I couldn't come up with a solution!")), log_categories::WARNING);
	Logger->send_to_GamePreviewLogger(FString(TEXT("Oh damn it! I couldn't come up with a solution!")), log_categories::WARNING, 3.0f);
	return false;
}

void AGOAPController::SetActionCost(const FName* ActionName, int32 Cost)
{
	GOAPPlanner.goap_set_cost(&ActionPlanner, ActionNames->Find(*ActionName), Cost);
}

int32 AGOAPController::GetActionValue(const  FName* ActionName)
{
	return BlackboardComp->GetValueAsInt(*ActionName);
}

bool AGOAPController::GetAtomState(const  FName* ActionName)
{
	return BlackboardComp->GetValueAsBool(*ActionName);
}

void AGOAPController::SetActionValue(const FName* ActionName, int32 Value)
{
	BlackboardComp->SetValueAsInt(*ActionName, Value);
}

void AGOAPController::SetAtomState(const FName* ActionName, bool Value)
{
	BlackboardComp->SetValueAsBool(*ActionName, Value);
}

void AGOAPController::ResetActionValues()
{
	for (auto const &Action : *ActionNames) {
		AGOAPController::ResetActionValue(&(Action.Key));
	}
}

void AGOAPController::ResetActionValue(const FName* ActionName)
{
	AGOAPController::SetActionValue(ActionName, DEFAULT_ACTION_VALUE);
}

bool AGOAPController::ResetLastSuccessfulAction()
{
	int32 max_utility = 0;
	FName  HighestValueAction = FName(TEXT(" "));

	for (auto const &Action : *ActionNames) {
		if (AGOAPController::GetActionValue(&(Action.Key)) >= max_utility)
		{
			max_utility = AGOAPController::GetActionValue(&(Action.Key));
			HighestValueAction = Action.Key;
		}
	}
	AGOAPController::ResetActionValue(&HighestValueAction);
	return true;
}

int32 AGOAPController::GetActualActionsUtilitySum()
{
	int32 sum = 0;
	for (auto const &WorldAtom : *ActionNames) {
		sum += AGOAPController::GetActionValue(&(WorldAtom.Key));
	}
	return sum;
}

void AGOAPController::SetActualPlanCost(const FName * PlanCostBlackboardKey, int32 PlanCost)
{
	BlackboardComp->SetValueAsInt(*PlanCostBlackboardKey, PlanCost);
}

void AGOAPController::SetActionPre(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue)
{
	GOAPPlanner.goap_set_pre(&ActionPlanner, ActionName, RelatedKey, RelatedKeyStateValue);
}

void AGOAPController::SetActionPst(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue)
{
	GOAPPlanner.goap_set_pst(&ActionPlanner, ActionName, RelatedKey, RelatedKeyStateValue);
}

void AGOAPController::GetActualWorldstate(GOAP::worldstate_t * ActualWorldState)
{	
}

void AGOAPController::SetActualWorldStateAtomValue(const char* AtomName, bool AtomValue)
{
	GOAPPlanner.goap_worldstate_set(&ActionPlanner, &ActualWorldState, AtomName, AtomValue);
}

void AGOAPController::SetDesiredWorldStateAtomValue(const char* AtomName, bool AtomValue)
{
	GOAPPlanner.goap_worldstate_set(&ActionPlanner, &DesiredWorldState, AtomName, AtomValue);
}

void AGOAPController::SetDesiredWorldstate(GOAP::worldstate_t * goal_worldstate)
{
}

bool AGOAPController::CheckGoal()
{
	AGOAPCharacter* GOAPCharacter = Cast<AGOAPCharacter>(GetPawn());
	if (GOAPCharacter)
	{
		GOAPCharacter->CalculateActionsCosts();
		GOAPCharacter->CheckGoal();
	}
	return true;
}