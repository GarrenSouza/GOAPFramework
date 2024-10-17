// Fill out your copyright notice in the Description page of Project Settings.

#include "CheckGoal.h"
#include "Core/GOAPController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <Engine/Engine.h>

EBTNodeResult::Type UCheckGoal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AGOAPController* GOAPController = Cast<AGOAPController>(OwnerComp.GetAIOwner());

	if (GOAPController) {
		auto Message = "Current Goal is: " + GOAPController->BlackboardComp->GetValueAsName(FName(TEXT(CURRENTGOAL_BB_KEY))).ToString();
		GOAPController->Logger->send_to_GamePreviewLogger(FString(Message), log_categories::DISPLAY, 3.0f);
		return (GOAPController->CheckGoal()) ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}
	return EBTNodeResult::Aborted;
}

