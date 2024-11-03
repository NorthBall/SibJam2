// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SGJ_QuestType.generated.h"


class ASGJ_QuestResultBoard;
class ASGJ_GoldPile;

UCLASS(Blueprintable, BlueprintType)
class SIBJAM2_API USGJ_QuestType : public UObject
{
	GENERATED_BODY()

public:
	USGJ_QuestType();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemsToCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CostPerItem;
	UPROPERTY(VisibleAnywhere)
	int32 ForgivenCalcError;
	UPROPERTY(BlueprintReadWrite)
	int32 ChosenCount;
	UPROPERTY(BlueprintReadWrite)
	int32 RealCount;
	UPROPERTY(BlueprintReadWrite)
	AActor* Adventurer;

	UPROPERTY(BlueprintReadWrite)
	ASGJ_GoldPile* GoldSource;
	UPROPERTY(BlueprintReadWrite)
	ASGJ_QuestResultBoard* ResultBoard;

	UPROPERTY(VisibleAnywhere)
	FText BoardIncomeName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText BoardPayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText BoardPenaltyName;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool GiveQuestToAdventurer(const FText& QuestDescription, FText& ErrorDescription);

	UFUNCTION(BlueprintCallable)
	void OnQuestGivenToAdventurer();
	UFUNCTION(BlueprintCallable)
	void OnQuestCompleted(FText CustomPaymentName);
};
