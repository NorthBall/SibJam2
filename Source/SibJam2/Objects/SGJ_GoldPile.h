// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SibJam2/Interaction/SGJ_Interactable.h"
#include "SGJ_GoldPile.generated.h"

UCLASS()
class SIBJAM2_API ASGJ_GoldPile : public AActor, public ISGJ_Interactable
{
	GENERATED_BODY()
	
public:	
	ASGJ_GoldPile();

	virtual void InteractWith_Implementation(AActor* Caller) override;
	virtual FText GetLookOnMessage_Implementation() override;

	UFUNCTION(BlueprintPure)
	int32 GetGold() const;
	UFUNCTION(BlueprintCallable)
	void SetGold(int32 NewGold);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GoldToWin;
	
protected:
	UPROPERTY()
	int32 Gold;
};
