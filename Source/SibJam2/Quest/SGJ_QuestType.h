// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "UObject/NoExportTypes.h"
#include "SGJ_QuestType.generated.h"


UCLASS(Blueprintable, BlueprintType)
class SIBJAM2_API USGJ_QuestType : public UObject
{
	GENERATED_BODY()

public:
	USGJ_QuestType();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemsToCount;
	UPROPERTY(BlueprintReadWrite)
	int32 ChosenCount;
	UPROPERTY(BlueprintReadWrite)
	AActor* Adventurer;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBehaviorTree* AdventurerQuestTree;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool GiveQuestToAdventurer(const FText& QuestDescription, FText& ErrorDescription);

	UFUNCTION(BlueprintCallable)
	void OnQuestGivenToAdventurer();
};
