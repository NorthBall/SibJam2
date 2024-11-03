// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGJ_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIBJAM2_API ASGJ_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASGJ_GameMode();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnGameWon();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnGameLost();
};
