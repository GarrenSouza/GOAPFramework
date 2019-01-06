// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GOAP.h"
#include "GOAPCharacter.generated.h"

UCLASS()
class GOAP_FRAMEWORK_API AGOAPCharacter : public ACharacter
{
	GENERATED_BODY()


protected:
	// Chamado quando a personagem "nasce" (spawn)
	virtual void BeginPlay() override;

public:
	AGOAPCharacter(const class FObjectInitializer& ObjectInitializer);			//Construtor da classe

	UPROPERTY(EditDefaultsOnly, Category = "AI")								//Exposi��o do componente BehaviorTree ao preenchimento atrav�s da vers�o Blueprint desta classe
		class UBehaviorTree* BehaviorTree;


	AGOAPCharacter();
	
	TMap<FName, const char> ActionNames = TMap<FName, const char>();			//Mapa que cont�m as poss�veis a��es desta personagem
	TMap<FName, int32> ActionValues = TMap<FName, int32>();						//Mapa que cont�m os valores de utilidade para cada a��o 
	TMap<FName, const char> ImportantAtoms = TMap<FName, const char>();			//Mapa que cont�m os �tomos mais importantes (o valor (const char) de cada �tomo define a urg�ncia de replanejamento resultante de sua modifica��o no mundo)
	TMap<FName, TArray<TTuple<FName, bool>>> Goals;								//Mapa que cont�m os objetivos desta personagem
	FName actual_goal_map_key;													//Chave do mapa que cont�m o objetivo atual da personagem que se encontra sob a posse desta inst�ncia de controlador
	FName last_goal_map_key;
	virtual void Tick(float DeltaTime) override;								//Chamado � cada intervalo DeltaTime

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void InitializeActions() PURE_VIRTUAL(AGOAPCharacter::InitializeActions, return ;);						//DEVE ser sobreescrito em classes filhas de GOAPCharacter
	virtual void InitializeImportantAtoms() PURE_VIRTUAL(AGOAPCharacter::InitializeImportantAtoms, return ;);		//DEVE ser sobreescrito em classes filhas de GOAPCharacter
	virtual void InitializeGoals() PURE_VIRTUAL(AGOAPCharacter::InitializeGoals, return;);							//DEVE ser sobreescrito em classes filhas de GOAPCharacter
	virtual void InitializeActionsCosts() PURE_VIRTUAL(AGOAPCharacter::InitializeActionsCosts, return;);			//DEVE ser sobreescrito em classes filhas de GOAPCharacter
	virtual void CalculateActionsCosts() PURE_VIRTUAL(AGOAPCharacter::CalculateActionsCosts, return;);				//DEVE ser sobreescrito em classes filhas de GOAPCharacter
	virtual void CheckGoal() PURE_VIRTUAL(AGOAPCharacter::CheckGoal, return;);										//DEVE ser sobreescrito em classes filhas de GOAPCharacter

};