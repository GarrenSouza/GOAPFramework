// Fill out your copyright notice in the Description page of Project Settings.

#include "RunPlanner.h"
#include "Core/GOAPController.h"

EBTNodeResult::Type URunPlanner::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AGOAPController* GOAPController = Cast<AGOAPController>(OwnerComp.GetAIOwner());
	if (GOAPController)
	{
		return (GOAPController->GetNewPlan()) ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}
	return EBTNodeResult::Failed;
}



