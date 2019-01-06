// Fill out your copyright notice in the Description page of Project Settings.

#include "AdjustUtilities.h"
#include "goap_framework/AI/GOAPFramework/GOAPController.h"

#ifndef TASKFAILED_BB_KEY
#define TASKFAILED_BB_KEY "TaskFailed"
#endif

EBTNodeResult::Type UAdjustUtilities::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AGOAPController* GOAPController = Cast<AGOAPController>(OwnerComp.GetAIOwner());
	if (GOAPController) {
		GOAPController->ResetLastSuccessfulAction();		//Como a última ação obteve sucesso, não é mais útil no plano atual
		if (!GOAPController->GetActualActionsUtilitySum())	//Teste utilizado para detectar o cumprimento do atual plano
		{
			FName TaskFailedKey = FName(TEXT(TASKFAILED_BB_KEY));
			GOAPController->SetAtomState(&TaskFailedKey, !GOAPController->GetAtomState(&TaskFailedKey));
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Aborted;
}
