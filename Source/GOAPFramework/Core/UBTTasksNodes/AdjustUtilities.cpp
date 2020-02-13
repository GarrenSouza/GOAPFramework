// Fill out your copyright notice in the Description page of Project Settings.

#include "AdjustUtilities.h"
#include "Core/GOAPController.h"

#ifndef PLANSTATECHANGED_BBKEY
#define PLANSTATECHANGED_BBKEY "PlanStateChanged"
#endif

EBTNodeResult::Type UAdjustUtilities::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AGOAPController* GOAPController = Cast<AGOAPController>(OwnerComp.GetAIOwner());
	if (GOAPController) {
		GOAPController->ResetLastSuccessfulAction();		//Como a ultima acao obteve sucesso, nao e mais util no plano atual
		if (GOAPController->GetActualActionsUtilitySum() == 0)	//Teste utilizado para detectar o cumprimento do atual plano
		{
			FName TaskFailedKey = FName(TEXT(PLANSTATECHANGED_BBKEY));
			GOAPController->SetAtomState(&TaskFailedKey, !GOAPController->GetAtomState(&TaskFailedKey));
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Aborted;
}

