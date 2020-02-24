// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GOAP.h"
#include "Styx/StyxLog.h"
#include "GOAPCharacter.generated.h"

UCLASS()
class GOAPFRAMEWORK_API AGOAPCharacter : public ACharacter
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	AGOAPCharacter(const class FObjectInitializer& ObjectInitializer);			//class constructor

	StyxLog Logger;

	UPROPERTY(EditDefaultsOnly, Category = "AI")								
		class UBehaviorTree* BehaviorTree;


	AGOAPCharacter();

	TMap<FName, const char> ActionNames = TMap<FName, const char>();			//Set containing the actions that the character is capable 
	TMap<FName, int32> ActionValues = TMap<FName, int32>();						//Set containing the utility value of the actions
	TMap<FName, const char> ImportantAtoms = TMap<FName, const char>();			//Set containing the necessary atoms for the planning process
	TMap<FName, TArray<TTuple<FName, bool>>> Goals;								//Set of goals
	FName actual_goal_map_key;													//Planning goal
	FName last_goal_map_key;													//Last goal planned
	virtual void Tick(float DeltaTime) override;								//Called every DeltaTime seconds

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void InitializeEntity() PURE_VIRTUAL(AGOAPCharacter::InitializeEntity, return;);						//Should be ovveride in child classes of GOAPCharacter
	virtual void InitializeActions() PURE_VIRTUAL(AGOAPCharacter::InitializeActions, return;);						//Should be override in child classes of GOAPCharacter
	virtual void InitializeImportantAtoms() PURE_VIRTUAL(AGOAPCharacter::InitializeImportantAtoms, return;);		//Should be override in child classes of GOAPCharacter
	virtual void InitializeGoals() PURE_VIRTUAL(AGOAPCharacter::InitializeGoals, return;);							//Should be override in child classes of GOAPCharacter
	virtual void InitializeActionsCosts() PURE_VIRTUAL(AGOAPCharacter::InitializeActionsCosts, return;);			//Should be override in child classes of GOAPCharacter
	virtual void CalculateActionsCosts() PURE_VIRTUAL(AGOAPCharacter::CalculateActionsCosts, return;);				//Should be override in child classes of GOAPCharacter
	virtual void CheckGoal() PURE_VIRTUAL(AGOAPCharacter::CheckGoal, return;);										//Should be override in child classes of GOAPCharacter

	
	
};
