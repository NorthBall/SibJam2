// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGJ_Hold_Sword.generated.h"

UCLASS()
class SIBJAM2_API ASGJ_Hold_Sword : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGJ_Hold_Sword();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetRarity(const FText& NewRarity);
	UFUNCTION(BlueprintPure)
	FText GetRarity() const;
	
protected:
	UPROPERTY(BlueprintReadWrite)
	FText Rarity;
};
