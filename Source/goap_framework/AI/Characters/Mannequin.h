// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/GOAPFramework/GOAPCharacter.h"
#include "Mannequin.generated.h"

/**
 * 
 */
UCLASS()
class GOAP_FRAMEWORK_API AMannequin : public AGOAPCharacter
{
	GENERATED_BODY()

public:

	void InitializeActions() override;			//Inicializa as ações desta personagem
	void InitializeImportantAtoms() override;	//Inicializa os átomos importantes ao comportamento desta personagem
	void InitializeGoals() override;			//Inicializa os objetivos desta personagem durante o tempo de execução
	void InitializeActionsCosts() override;		//Inicializa os custos de cada ação desempenhada por esta personagem
	void CalculateActionsCosts() override;
	void CheckGoal() override;
};
