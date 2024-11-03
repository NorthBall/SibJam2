// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SibJam2/Interaction/SGJ_Interactable.h"
#include "SGJ_QuestResultBoard.generated.h"

UCLASS()
class SIBJAM2_API ASGJ_QuestResultBoard : public AActor, public ISGJ_Interactable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASGJ_QuestResultBoard();

	virtual void InteractWith_Implementation(AActor* Caller) override;
	virtual FText GetLookOnMessage_Implementation() override;

	UPROPERTY(BlueprintReadWrite)
	TArray<FText> IncomeArray;
	UPROPERTY(BlueprintReadWrite)
	TArray<FText> ExpenseArray;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UpdateWidget();
};
