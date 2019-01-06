// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "AI/GOAPFramework/GOAPController.h"

void AMannequin::InitializeImportantAtoms()
{
		ImportantAtoms.Add(FName(TEXT("HaveAxe")), *("HaveAxe"));
		ImportantAtoms.Add(FName(TEXT("HaveAxeMoney")), *("HaveAxeMoney"));
		ImportantAtoms.Add(FName(TEXT("InForest")), *("InForest"));
		ImportantAtoms.Add(FName(TEXT("InShop")), *("InShop"));
		ImportantAtoms.Add(FName(TEXT("HaveTShirtMoney")), *("HaveTShirtMoney"));
		ImportantAtoms.Add(FName(TEXT("HaveTwigs")), *("HaveTwigs"));
		ImportantAtoms.Add(FName(TEXT("HaveTShirt")), *("HaveTShirt"));
		ImportantAtoms.Add(FName(TEXT("HaveWood")), *("HaveWood"));
		ImportantAtoms.Add(FName(TEXT("UnderThreat")), *("UnderThreat"));
		ImportantAtoms.Add(FName(TEXT("Vulnerable")), *("Vulnerable"));
}

void AMannequin::InitializeActionsCosts()
{
	AGOAPController* GOAPController = Cast<AGOAPController>(GetController());
	if (GOAPController)
	{
		//GOAPController->SetActionCost()
	}
}

void AMannequin::CalculateActionsCosts()
{
	//calcular
	//
}

void AMannequin::InitializeGoals()
{
	AGOAPController* GOAPController = Cast<AGOAPController>(GetController());
	if (GOAPController)
	{
		//ActualWorldState description
		GOAPController->SetActualWorldStateAtomValue("HaveAxe", false);
		GOAPController->SetActualWorldStateAtomValue("HaveAxeMoney", false);
		GOAPController->SetActualWorldStateAtomValue("InForest", false);
		GOAPController->SetActualWorldStateAtomValue("InShop", true);
		GOAPController->SetActualWorldStateAtomValue("HaveTShirtMoney", false);
		GOAPController->SetActualWorldStateAtomValue("HaveTwigs", false);
		GOAPController->SetActualWorldStateAtomValue("HaveTShirt", false);
		GOAPController->SetActualWorldStateAtomValue("HaveWood", false);
		GOAPController->SetActualWorldStateAtomValue("AmbushCondition", false);
		GOAPController->SetActualWorldStateAtomValue("Vulnerable", false);

		//DesiredWorldState description

		TArray<TTuple<FName, bool>> MainGoal = TArray<TTuple<FName, bool>>();
		MainGoal.Emplace("HaveTShirt", false);
		Goals.Add("MAIN", MainGoal);

		TArray<TTuple<FName, bool>> RestoreHealthGoal = TArray<TTuple<FName, bool>>();
		RestoreHealthGoal.Emplace("HaveTShirt", false);
		Goals.Add("RestoreHealthGoal", RestoreHealthGoal);

		GOAPController->SetDesiredWorldStateAtomValue("HaveTShirt", true);

		last_goal_map_key = actual_goal_map_key = "MAIN";
	}
}

void AMannequin::InitializeActions() 
{
	AGOAPController* GOAPController = Cast<AGOAPController>(GetController());
	if (GOAPController)
	{
		//Fill the Actions list of the character (SHOULD MATCH the variable names in the respective Blackboard asset)
		ActionNames.Add(FName(TEXT("GoToForest")), *("GoToForest"));
		ActionNames.Add(FName(TEXT("FindTwigs")), *("FindTwigs"));
		ActionNames.Add(FName(TEXT("GoToShop")), *("GoToShop"));
		ActionNames.Add(FName(TEXT("SellTwigs")), *("SelllTwigs"));
		ActionNames.Add(FName(TEXT("BuyAxe")), *("BuyAxe"));
		ActionNames.Add(FName(TEXT("FindWood")), *("FindWood"));
		ActionNames.Add(FName(TEXT("SellWood")), *("SellWood"));
		ActionNames.Add(FName(TEXT("BuyTShirt")), *("BuyTShirt"));

		//Insert the Actions in the Planner


		//GoToForest
		GOAPController->SetActionPre("GoToForest", "InForest", false);
		GOAPController->SetActionPst("GoToForest", "InForest", true);
		GOAPController->SetActionPst("GoToForest", "InShop", false);

		//FindTwigs
		GOAPController->SetActionPre("FindTwigs", "InForest", true);
		GOAPController->SetActionPre("FindTwigs", "HaveTwigs", false);
		GOAPController->SetActionPst("FindTwigs", "HaveTwigs", true);

		//GoToShop
		GOAPController->SetActionPre("GoToShop", "InShop", false);
		GOAPController->SetActionPst("GoToShop", "InShop", true);
		GOAPController->SetActionPst("GoToShop", "InForest", false);;

		//SellTwigs
		GOAPController->SetActionPre("SellTwigs", "HaveTwigs", true);
		GOAPController->SetActionPre("SellTwigs", "InShop", true);
		GOAPController->SetActionPst("SellTwigs", "HaveAxeMoney", true);
		GOAPController->SetActionPst("SellTwigs", "HaveTwigs", false);

		//BuyAxe
		GOAPController->SetActionPre("BuyAxe", "HaveAxeMoney", true);
		GOAPController->SetActionPre("BuyAxe", "HaveAxe", false);
		GOAPController->SetActionPre("BuyAxe", "InShop", true);
		GOAPController->SetActionPst("BuyAxe", "HaveAxeMoney", false);
		GOAPController->SetActionPst("BuyAxe", "HaveAxe", true);

		//FindWood
		GOAPController->SetActionPre("FindWood", "InForest", true);
		GOAPController->SetActionPre("FindWood", "HaveAxe", true);
		GOAPController->SetActionPst("FindWood", "HaveWood", true);

		//SellWood
		GOAPController->SetActionPre("SellWood", "HaveWood", true);
		GOAPController->SetActionPre("SellWood", "InShop", true);
		GOAPController->SetActionPst("SellWood", "HaveTShirtMoney", true);
		GOAPController->SetActionPst("SellWood", "HaveWood", false);

		//BuyTShirt
		GOAPController->SetActionPre("BuyTShirt", "HaveTShirtMoney", true);
		GOAPController->SetActionPst("BuyTShirt", "HaveTShirt", true);
		GOAPController->SetActionPst("BuyTShirt", "HaveTShirtMoney", false);
	}
}

void AMannequin::CheckGoal()
{
}