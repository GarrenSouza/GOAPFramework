// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GOAP.h"
#include "AIController.h"
#include "CoreMinimal.h"
#include "AStar.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GOAPController.generated.h"

/**
* Classe principal de controle de uma personagem (compatível com instâncias de AGOAPCharacter)
*/
UCLASS()
class GOAP_FRAMEWORK_API AGOAPController : public AAIController
{
	GENERATED_BODY()

	AGOAPController(const class FObjectInitializer& ObjectInitializer);//Inicializador

	AStar AStarPlanner;									//Instância que será utilizada no que se refere ao processo de "Pathfinding"
	GOAP GOAPPlanner;									//Instância que será utilizada na execução de métodos não estáticos GOAP

protected:
	//Planning
	GOAP::actionplanner_t ActionPlanner;				//Utilizado no planejamento
	GOAP::worldstate_t ActualWorldState;				//Atual estado dos átomos envolvidos
	GOAP::worldstate_t DesiredWorldState;				//Estado desejado dos átomos, no qual o objetivo se encontra cumprido
	void DestroyControlledCharacter();					//Destrói o personagem que se encontra em posse desta instância de GOAPController
	virtual void Possess(class APawn* InPawn) override;	//Chamado quando o controlador toma posse de uma personagem
	virtual void UnPossess() override;					//Chamado quando o controlador abre mão da posse de uma personagem

public:
	//Brain
	UBehaviorTreeComponent * BehaviorComp;	//Componente que será utilizado para controlar a personagem possuída por este controlador
	UBlackboardComponent* BlackboardComp;	//Componente que será utilizado para guardar os valores necessários ao funcionamento do componente BehaviorComp

	//Planning
	bool GetNewPlan();											//Replanejar a nova sequência de ações
	void SetActualPlanCost(const FName* PlanCostBlackboardKey, int32 PlanCost);	//Insere o custo do plano na instância de Blackboard
	
	//Storage
	TMap<FName, const char>* ActionNames;						//Mapa que contém as possíveis ações desta personagem
	TMap<FName, int32>* ActionValues;							//Mapa que contém os valores de utilidade das ações
	TMap<FName, const char>* ImportantAtoms;					//Mapa que contém os átomos mais importantes 
	TMap<FName, TArray<TTuple<FName, bool>>>* Goals;			//Mapa que contém os objetivos desta personagem
	FName* actual_goal_map_key;									//Chave do mapa que contém o objetivo atual da personagem que se encontra sob a posse desta instância de controlador
	FName* last_goal_map_key;

	//Actions (Values)
	int32 GetActionValue(const FName* ActionName);				//Obter o valor de utilidade de uma ação 
	void SetActionValue(const FName* ActionName, int32 Value);	//Inserir o valor de utilidade de uma ação 
	void SetActionCost(const FName* ActionName, int32 Cost);	//Insere o custo de uma dada ação na instância de GOAPPlanner
	void ResetActionValues();									//Todas as ações recebem índice de utilidade 0 (zero)
	void ResetActionValue(const FName* ActionName);				//A ação recebida receberá índice de utilidade 0 (zero)
	bool ResetLastSuccessfulAction();							//A ação com o maior índice de utilidade no momento da chamada receberá índice 0, fazendo com que a ação imediatamente seguinte seja a mais útil
	int32 GetActualActionsUtilitySum();							//Retorna a soma dos índices de utilidade, utilizado para checar êxito de um plano

	//Atoms (States)
	bool GetAtomState(const FName* ActionName);					//Obter o estado de um determinado átomo do mundo
	void SetAtomState(const FName* ActionName, bool Value);		//Inserir o estado de um determinado átomo no mundo

	//Actions pre/pst
	void SetActionPre(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue);	//Insere no ActionPlanner da classe os requisitos para a utilização de uma ação
	void SetActionPst(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue);	//Insere no ActionPlanner da classe as consequências da utilização de uma ação

	//WorldState (actual/desired)
	void GetActualWorldstate(GOAP::worldstate_t* ActualWorldState);				//Obter a situação dos átomos no atual mundo 
	void SetActualWorldStateAtomValue(const char* AtomName, bool AtomValue);	//Define o estado de um átomo na representação atual de mundo	
	void SetDesiredWorldStateAtomValue(const char* AtomName, bool AtomValue);	//Define o estado de um átomo na representação desejada de mundo
	void SetDesiredWorldstate(GOAP::worldstate_t* GoalWorldstate);				//Define os átomos do mundo no qual o objetivo se encontra satisfeito

	//Goal Management
	bool CheckGoal();															//Irá gerenciar os objetivos

	//Components (BT/BB)
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }	//Retorna o componente de comportamento (BehaviorTree)
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }	//Retorna o componente de "memória" utilizado pela classe (Blackboard)
};

