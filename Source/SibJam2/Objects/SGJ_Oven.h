// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SibJam2/Interaction/SGJ_Interactable.h"
#include "SGJ_Oven.generated.h"

class ASGJ_Timer_Watch;

UCLASS()
class SIBJAM2_API ASGJ_Oven : public AActor, public ISGJ_Interactable
{
	GENERATED_BODY()
	
public:	
	ASGJ_Oven();

	virtual void InteractWith_Implementation(AActor* Caller) override;
	virtual FText GetLookOnMessage_Implementation() override;

	UPROPERTY(EditAnywhere)
	ASGJ_Timer_Watch* TimerWatch;

	UFUNCTION(BlueprintNativeEvent)
	void BakeCake();
	UFUNCTION(BlueprintNativeEvent)
	void BakeFirewood();
};
