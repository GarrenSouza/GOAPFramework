// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GOAP.h"
#include "AIController.h"
#include "CoreMinimal.h"
#include "AStar.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GOAPController.generated.h"

/**
* Classe principal de controle de uma personagem (compat�vel com inst�ncias de AGOAPCharacter)
*/
UCLASS()
class GOAP_FRAMEWORK_API AGOAPController : public AAIController
{
	GENERATED_BODY()

	AGOAPController(const class FObjectInitializer& ObjectInitializer);//Inicializador

	AStar AStarPlanner;									//Inst�ncia que ser� utilizada no que se refere ao processo de "Pathfinding"
	GOAP GOAPPlanner;									//Inst�ncia que ser� utilizada na execu��o de m�todos n�o est�ticos GOAP

protected:
	//Planning
	GOAP::actionplanner_t ActionPlanner;				//Utilizado no planejamento
	GOAP::worldstate_t ActualWorldState;				//Atual estado dos �tomos envolvidos
	GOAP::worldstate_t DesiredWorldState;				//Estado desejado dos �tomos, no qual o objetivo se encontra cumprido
	void DestroyControlledCharacter();					//Destr�i o personagem que se encontra em posse desta inst�ncia de GOAPController
	virtual void Possess(class APawn* InPawn) override;	//Chamado quando o controlador toma posse de uma personagem
	virtual void UnPossess() override;					//Chamado quando o controlador abre m�o da posse de uma personagem

public:
	//Brain
	UBehaviorTreeComponent * BehaviorComp;	//Componente que ser� utilizado para controlar a personagem possu�da por este controlador
	UBlackboardComponent* BlackboardComp;	//Componente que ser� utilizado para guardar os valores necess�rios ao funcionamento do componente BehaviorComp

	//Planning
	bool GetNewPlan();											//Replanejar a nova sequ�ncia de a��es
	void SetActualPlanCost(const FName* PlanCostBlackboardKey, int32 PlanCost);	//Insere o custo do plano na inst�ncia de Blackboard
	
	//Storage
	TMap<FName, const char>* ActionNames;						//Mapa que cont�m as poss�veis a��es desta personagem
	TMap<FName, int32>* ActionValues;							//Mapa que cont�m os valores de utilidade das a��es
	TMap<FName, const char>* ImportantAtoms;					//Mapa que cont�m os �tomos mais importantes 
	TMap<FName, TArray<TTuple<FName, bool>>>* Goals;			//Mapa que cont�m os objetivos desta personagem
	FName* actual_goal_map_key;									//Chave do mapa que cont�m o objetivo atual da personagem que se encontra sob a posse desta inst�ncia de controlador
	FName* last_goal_map_key;

	//Actions (Values)
	int32 GetActionValue(const FName* ActionName);				//Obter o valor de utilidade de uma a��o 
	void SetActionValue(const FName* ActionName, int32 Value);	//Inserir o valor de utilidade de uma a��o 
	void SetActionCost(const FName* ActionName, int32 Cost);	//Insere o custo de uma dada a��o na inst�ncia de GOAPPlanner
	void ResetActionValues();									//Todas as a��es recebem �ndice de utilidade 0 (zero)
	void ResetActionValue(const FName* ActionName);				//A a��o recebida receber� �ndice de utilidade 0 (zero)
	bool ResetLastSuccessfulAction();							//A a��o com o maior �ndice de utilidade no momento da chamada receber� �ndice 0, fazendo com que a a��o imediatamente seguinte seja a mais �til
	int32 GetActualActionsUtilitySum();							//Retorna a soma dos �ndices de utilidade, utilizado para checar �xito de um plano

	//Atoms (States)
	bool GetAtomState(const FName* ActionName);					//Obter o estado de um determinado �tomo do mundo
	void SetAtomState(const FName* ActionName, bool Value);		//Inserir o estado de um determinado �tomo no mundo

	//Actions pre/pst
	void SetActionPre(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue);	//Insere no ActionPlanner da classe os requisitos para a utiliza��o de uma a��o
	void SetActionPst(const char* ActionName, const char* RelatedKey, bool RelatedKeyStateValue);	//Insere no ActionPlanner da classe as consequ�ncias da utiliza��o de uma a��o

	//WorldState (actual/desired)
	void GetActualWorldstate(GOAP::worldstate_t* ActualWorldState);				//Obter a situa��o dos �tomos no atual mundo 
	void SetActualWorldStateAtomValue(const char* AtomName, bool AtomValue);	//Define o estado de um �tomo na representa��o atual de mundo	
	void SetDesiredWorldStateAtomValue(const char* AtomName, bool AtomValue);	//Define o estado de um �tomo na representa��o desejada de mundo
	void SetDesiredWorldstate(GOAP::worldstate_t* GoalWorldstate);				//Define os �tomos do mundo no qual o objetivo se encontra satisfeito

	//Goal Management
	bool CheckGoal();															//Ir� gerenciar os objetivos

	//Components (BT/BB)
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }	//Retorna o componente de comportamento (BehaviorTree)
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }	//Retorna o componente de "mem�ria" utilizado pela classe (Blackboard)
};

