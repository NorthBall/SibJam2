// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGJ_QuestStructs.h"
#include "Engine/DataAsset.h"
#include "SGJ_RandomizedDialogue.generated.h"

UCLASS(BlueprintType)
class SIBJAM2_API USGJ_RandomizedDialogue : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<FSGJ_DialogueInfo> DialogueLines;
};
