// Copyright Epic Games, Inc. All Rights Reserved.

#include "SibJam2GameMode.h"
#include "SibJam2Character.h"
#include "UObject/ConstructorHelpers.h"

ASibJam2GameMode::ASibJam2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
