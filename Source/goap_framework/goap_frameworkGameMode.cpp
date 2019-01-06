// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "goap_frameworkGameMode.h"
#include "goap_frameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"

Agoap_frameworkGameMode::Agoap_frameworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
