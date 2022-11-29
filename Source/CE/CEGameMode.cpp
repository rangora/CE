// Copyright Epic Games, Inc. All Rights Reserved.

#include "CEGameMode.h"
#include "CECharacter.h"
#include "UObject/ConstructorHelpers.h"

ACEGameMode::ACEGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
