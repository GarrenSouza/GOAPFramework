// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/GOAPCharacter.h"
#include "FacelessGuy.generated.h"

/**
 * 
 */
UCLASS()
class GOAPFRAMEWORK_API AFacelessGuy : public AGOAPCharacter
{
	GENERATED_BODY()
	
public:
	void InitializeActions() override;			
	void InitializeImportantAtoms() override;	
	void InitializeGoals() override;			
	void InitializeActionsCosts() override;		
	void CalculateActionsCosts() override;
	void CheckGoal() override;
	
	
};
