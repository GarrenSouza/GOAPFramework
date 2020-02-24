// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GOAP.h"
#include "AIController.h"
#include "CoreMinimal.h"
#include "AStar.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Styx/StyxLog.h"
#include "GOAPController.generated.h"

/**
* Main class of character control (AGOAPCharacter compatible only)
*/
UCLASS()
class GOAPFRAMEWORK_API AGOAPController : public AAIController
{
	GENERATED_BODY()


	AGOAPController(const class FObjectInitializer& ObjectInitializer);//Initializer

	AStar AStarPlanner;									// Action/State-Graph Pathfinding planner
	GOAP GOAPPlanner;									// GOAP planner

protected:
	//Planning
	GOAP::actionplanner_t ActionPlanner;				
	GOAP::worldstate_t ActualWorldState;				//Set containing the ACTUAL atom states
	GOAP::worldstate_t DesiredWorldState;				//Set containing the DESIRED atom states
	void DestroyControlledCharacter();					//Destroy the controlled character
	virtual void Possess(class APawn* InPawn) override;	//Called once the controller is taking control over some character
	virtual void UnPossess() override;					//Called once the controller is detached of the character

public:
	//Action articulator
	UBehaviorTreeComponent * BehaviorComp;	//The component where the actions of the character will be attached
	UBlackboardComponent* BlackboardComp;	//The component where the atoms of the character will be stored

	//Logging
	StyxLog* Logger;

	//Planning
	bool GetNewPlan();											
	void SetActualPlanCost(const FName* PlanCostBlackboardKey, int32 PlanCost);	//Set the cost of the actual plan on the Blackboard

	//Storage
	TMap<FName, const char>* ActionNames;						//Set containing the actions that the character is capable 
	TMap<FName, int32>* ActionValues;							//Set containing the utility value of the actions
	TMap<FName, const char>* ImportantAtoms;					//Set containing the necessary atoms for the planning process
	TMap<FName, TArray<TTuple<FName, bool>>>* Goals;			//Set of goals
	FName* actual_goal_map_key;									//Planning goal
	FName* last_goal_map_key;									//Last goal planned

	//Actions (Values)
	int32 GetActionValue(const FName* ActionName);				//Get action utility value
	void SetActionValue(const FName* ActionName, int32 Value);	//Set action utility value
	void SetActionCost(const FName* ActionName, int32 Cost);	//Set action cost
	void ResetActionValues();									//Set the cost of all actions to 0 (zero)
	void ResetActionValue(const FName* ActionName);				//Set the cost of the given action to 0 (zero)
	bool ResetLastSuccessfulAction();							//Set the cost of the last successfull action to 0 (zero)
	int32 GetActualActionsUtilitySum();							//Return the sum of the action utility indexes within the actual plan

	//Atoms (States)
	bool GetAtomState(const FName* ActionName);					//Get atom state
	void SetAtomState(const FName* ActionName, bool Value);		//Set atom state

	//Actions pre/pst
	void SetActionPre(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue);	//Set the requisites of a given action
	void SetActionPst(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue);	//Set the consequences of a given action

	//WorldState (actual/desired)
	void GetActualWorldstate(GOAP::worldstate_t* ActualWorldState);				//Get the set of atom states of the actual world
	void SetActualWorldStateAtomValue(const char* AtomName, bool AtomValue);	//Set the set of atom states of the actual world
	void SetDesiredWorldStateAtomValue(const char* AtomName, bool AtomValue);	//Set the desired state of a given atom
	void SetDesiredWorldstate(GOAP::worldstate_t* GoalWorldstate);				//Set the set of atom states of the desired world

	//Goal Management
	bool CheckGoal();															//Goal management dynamics

	//Components (BT/BB)
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }	//Get the Behavior Tree component
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }	//Get the Blacboard component
};

