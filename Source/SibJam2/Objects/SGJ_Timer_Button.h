// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SibJam2/Interaction/SGJ_Interactable.h"
#include "SGJ_Timer_Button.generated.h"

class ASGJ_Timer_Watch;

UENUM(BlueprintType)
enum ESGJ_TimerStates
{
	Idle UMETA(DisplayName = "Idle"),
	Started UMETA(DisplayName = "Started"),
	Ringed UMETA(DisplayName = "Ringed")
};

UCLASS()
class SIBJAM2_API ASGJ_Timer_Button : public AActor, public ISGJ_Interactable
{
	GENERATED_BODY()
	
public:	
	ASGJ_Timer_Button();

	virtual void InteractWith_Implementation(AActor* Caller) override;
	virtual FText GetLookOnMessage_Implementation() override;

	UPROPERTY()
	TEnumAsByte<ESGJ_TimerStates> TimerState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ASGJ_Timer_Watch* TimerWatch;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnTimerStarted();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnTimerRinged();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnTimerEnded();

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnTimerStateUpdated();
};
