// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGJ_QuestStructs.h"
#include "Engine/DataAsset.h"
#include "SGJ_RandomNames.generated.h"


UCLASS(BlueprintType)
class SIBJAM2_API USGJ_RandomNames : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FString, FSGJ_NameArray> NameMap;
};
