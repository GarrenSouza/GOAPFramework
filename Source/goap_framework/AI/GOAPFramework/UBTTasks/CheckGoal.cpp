// Fill out your copyright notice in the Description page of Project Settings.

#include "CheckGoal.h"
#include "goap_framework/AI/GOAPFramework/GOAPController.h"

EBTNodeResult::Type UCheckGoal::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AGOAPController* GOAPController = Cast<AGOAPController>(OwnerComp.GetAIOwner());
	if (GOAPController) {
		return (GOAPController->CheckGoal()) ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}
	return EBTNodeResult::Aborted;
}
	