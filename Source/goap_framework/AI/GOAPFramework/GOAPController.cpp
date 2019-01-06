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

#ifndef TASKFAILED_KEY
#define TASKFAILED_BBKEY "TaskFailed"
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
	bWantsPlayerState = true;										//Personagem recebe um ID
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
	AGOAPCharacter* GOAPCharacter = Cast<AGOAPCharacter>(InPawn);	//pure member functions s�o demais :-D

	if (GOAPCharacter)
	{
		if (GOAPCharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*GOAPCharacter->BehaviorTree->BlackboardAsset);
			ActionNames = &(GOAPCharacter->ActionNames);
			ImportantAtoms = &(GOAPCharacter->ImportantAtoms);
			actual_goal_map_key = &(GOAPCharacter->actual_goal_map_key);
			last_goal_map_key = &(GOAPCharacter->last_goal_map_key);
			Goals = &(GOAPCharacter->Goals);

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
		BehaviorComp->StopLogic(TEXT("Esta inst�ncia de GOAPCharacter n�o possui mais um controlador"));
		BehaviorComp->StopTree();
	}
}

bool AGOAPController::GetNewPlan()
{
	char desc[4096];													//Buffer de descri��o usado para DEBUG
	const char* Plan[16];												//Vetor que conter� o plano
	int32 PlanSize = 16;												//Tamanho m�ximo do plano
	GOAP::worldstate_t States[16];										//Quantidade de estados (m�xima) para que se chegue ao estado de mundo desejado

	GOAPPlanner.goap_description(&ActionPlanner, desc, sizeof(desc));	//Usado para debug
	AGOAPController::GetActualWorldstate(&ActualWorldState);			//Atualiza vis�o de mundo
	AGOAPController::SetDesiredWorldstate(&DesiredWorldState);			//Atualiza Objetivo
	int32 PlanCost = AStarPlanner.astar_plan(&ActionPlanner, ActualWorldState, DesiredWorldState, Plan, States, &PlanSize);													//Custo do plano
	
	FName BBTaskKeyFailed = FName(TEXT(TASKFAILED_BBKEY));
	AGOAPController::SetAtomState(&BBTaskKeyFailed, false);				//Atua sobre o la�o de repeti��o das a��es dentro do componente "BehaviorComp"

	if (PlanCost != -1)
	{
		GOAPPlanner.goap_worldstate_description(&ActionPlanner, &ActualWorldState, desc, sizeof(desc));	//Usado para debug
		AGOAPController::ResetActionValues();
		GOAPPlanner.goap_worldstate_description(&ActionPlanner, &ActualWorldState, desc, sizeof(desc));	//Usado para debug
		int ActionUtility = PlanSize;											//PlanSize cont�m a quantidade de a��es que o plano preparado possui
		AGOAPController::ResetActionValues();
		for (int32 i = 0; ((i < PlanSize) && (i < 16)); i++)
		{
			FName ActionName = Plan[i];							//Pr�ximo est�gio do plano
			if(!AGOAPController::GetActionValue(&ActionName))	//==0, evita que a repeti��o de uma a��o dentro do plano sobreescreva uma chamada anterior 
			{
				AGOAPController::SetActionValue(&ActionName, ActionUtility--);	//Cada a��o recebe o seu �ndice de utilidade
				continue;
			}
			break;
		}
		FName BBPlanCostKey = FName(TEXT(PLANCOST_BBKEY));
		AGOAPController::SetActualPlanCost(&BBPlanCostKey,PlanCost);
		return true;
	}
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
	for (auto const &Action: *ActionNames) {
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
	FName  HighestAction = FName(TEXT("GoToForest"));

	for (auto const &Action : *ActionNames) {
		if (AGOAPController::GetActionValue(&(Action.Key)) >= max_utility)
		{
			max_utility = AGOAPController::GetActionValue(&(Action.Key));
			HighestAction = Action.Key;
		}
	}	
	AGOAPController::ResetActionValue(&HighestAction);
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
	for (auto const &WorldAtom : *ImportantAtoms) {
		bool AtomValue = BlackboardComp->GetValueAsBool(WorldAtom.Key);
		AGOAPController::SetActualWorldStateAtomValue(&WorldAtom.Value, AtomValue);
	}
	//Realizar a coleta de informa��es �teis ao controlador, inserindo-as na estrutura apontada pelo par�metro "ActualWorldState"
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
	TArray<TTuple<FName, bool>>* actual_goal;
	FName pppasd;
	actual_goal = Goals->Find(*actual_goal_map_key);
	for (auto const &WorldAtom : *actual_goal) {
		SetDesiredWorldStateAtomValue(ImportantAtoms->Find(WorldAtom.Key), WorldAtom.Value);
	}
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
