// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SibJam2GameState.generated.h"

/**
 * 
 */
UCLASS()
class SIBJAM2_API ASibJam2GameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APawn* SpawnedBot;
};
