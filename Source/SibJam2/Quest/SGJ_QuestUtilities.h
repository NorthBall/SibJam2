// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGJ_QuestStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SGJ_QuestUtilities.generated.h"

/**
 * 
 */
UCLASS()
class SIBJAM2_API USGJ_QuestUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FText GetRandomDialogue(const TArray<FSGJ_DialogueInfo>& DialogueArray, const TMap<FString, FSGJ_NameArray>& NameMap, const ESGJ_DialogueType
	                               DialogueType);
};
