// Fill out your copyright notice in the Description page of Project Settings.

#include "GOAPCharacter.h"
#include "GOAPController.h"


AGOAPCharacter::AGOAPCharacter(const FObjectInitializer & ObjectInitializer)
{
}


// Sets default values
AGOAPCharacter::AGOAPCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void AGOAPCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGOAPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateActionsCosts();
}

// Called to bind functionality to input
//void AGOAPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);

//}


