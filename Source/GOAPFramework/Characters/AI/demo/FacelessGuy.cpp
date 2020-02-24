// Fill out your copyright notice in the Description page of Project Settings.

#include "FacelessGuy.h"
#include "Core/GOAPController.h"
#include "Styx/StyxLog.h"

void AFacelessGuy::InitializeEntity() {
	Logger.setMyName(GetNameSafe(this));
}

void AFacelessGuy::InitializeImportantAtoms()
{
	//Logger.send_to_Output_logger(FString(TEXT("Initializing relevant atoms!")), log_categories::DISPLAY);
	
	ImportantAtoms.Add(FName(TEXT("LowHealth")), *("LowHealth"));
	ImportantAtoms.Add(FName(TEXT("EnemyAlive")), *("EnemyAlive"));
	ImportantAtoms.Add(FName(TEXT("MemoryLevel1")), *("MemoryLevel1"));
	ImportantAtoms.Add(FName(TEXT("InCloseRange")), *("InCloseRange"));
	ImportantAtoms.Add(FName(TEXT("InMiddleRange")), *("InMiddleRange"));
	ImportantAtoms.Add(FName(TEXT("HaveSafeSpot")), *("HaveSafeSpot"));
	ImportantAtoms.Add(FName(TEXT("UnderThreat")), *("UnderThreat"));
	ImportantAtoms.Add(FName(TEXT("InBattle")), *("InBattle"));
}


void AFacelessGuy::InitializeGoals()
{
	AGOAPController* GOAPController = Cast<AGOAPController>(GetController());
	if (GOAPController)
	{
		Logger.send_to_Output_logger(FString(TEXT("Initializing goals!")), log_categories::DISPLAY);

		//Description of the actual worldstate
		GOAPController->SetActualWorldStateAtomValue("LowHealth", true);
		GOAPController->SetActualWorldStateAtomValue("EnemyAlive", true);
		GOAPController->SetActualWorldStateAtomValue("MemoryLevel1", false);
		GOAPController->SetActualWorldStateAtomValue("InCloseRange", true);
		GOAPController->SetActualWorldStateAtomValue("InMiddleRange", false);
		GOAPController->SetActualWorldStateAtomValue("HaveSafeSpot", false);
		GOAPController->SetActualWorldStateAtomValue("UnderThreat", true);
		GOAPController->SetActualWorldStateAtomValue("InBattle", true);

		//Description of the MAIN Goal
		TArray<TTuple<FName, bool>> MainGoal = TArray<TTuple<FName, bool>>();
		MainGoal.Emplace("LowHealth", false);
		Goals.Add("MAIN", MainGoal);

		//Description of a secondary goal (self preservation)
		TArray<TTuple<FName, bool>> RestoreHealthGoal = TArray<TTuple<FName, bool>>();
		RestoreHealthGoal.Emplace("HaveSafeSpot", true);
		Goals.Add("RestoreHealthGoal", RestoreHealthGoal);

		GOAPController->SetDesiredWorldStateAtomValue("LowHealth", false);

		last_goal_map_key = actual_goal_map_key = "MAIN";
		//Description of the desired worldstate
	}
}


void AFacelessGuy::InitializeActionsCosts()
{
}


void AFacelessGuy::CalculateActionsCosts()
{
}


void AFacelessGuy::InitializeActions()
{
	AGOAPController* GOAPController = Cast<AGOAPController>(GetController());
	if (GOAPController)
	{
		//Logger.send_to_Output_logger(FString(TEXT("Initializing actions!")), log_categories::DISPLAY);

		//Action Set
		ActionNames.Add(FName(TEXT("DoubleSwipe")), *("DoubleSwipe"));
		ActionNames.Add(FName(TEXT("PoisonBall")), *("PoisonBall"));
		ActionNames.Add(FName(TEXT("FindSafeSpot")), *("FindSafeSpot"));
		ActionNames.Add(FName(TEXT("MoveToSafeSpot")), *("MoveToSafeSpot"));
		ActionNames.Add(FName(TEXT("Cure")), *("Cure"));

		//DoubleSwipe
		GOAPController->SetActionPre("DoubleSwipe", "InCloseRange", true);
		GOAPController->SetActionPst("DoubleSwipe", "EnemyAlive", false);

		//PoisonBall
		GOAPController->SetActionPre("PoisonBall", "InMiddleRange", true);
		GOAPController->SetActionPre("PoisonBall", "MemoryLevel1", true);
		GOAPController->SetActionPst("PoisonBall", "EnemyAlive", false);

		//FindSafeSpot
		GOAPController->SetActionPst("FindSafeSpot", "HaveSafeSpot", true);

		//MoveToSafeSpot
		GOAPController->SetActionPre("MoveToSafeSpot", "HaveSafeSpot", true);
		GOAPController->SetActionPst("MoveToSafeSpot", "InBattle", false);
		GOAPController->SetActionPst("MoveToSafeSpot", "HaveSafeSpot", false);
		GOAPController->SetActionPst("MoveToSafeSpot", "UnderThreat", false);

		//Cure
		GOAPController->SetActionPre("Cure", "UnderThreat", false);
		GOAPController->SetActionPre("Cure", "InBattle", false);
		GOAPController->SetActionPst("Cure", "LowHealth", false);
		GOAPController->SetActionPst("Cure", "InBattle", true);
	}
}

//Goal switching dynamics goes here
void AFacelessGuy::CheckGoal()
{
}

