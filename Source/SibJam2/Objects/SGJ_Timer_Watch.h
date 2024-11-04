// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGJ_Timer_Watch.generated.h"

class ASGJ_Timer_Button;

UCLASS()
class SIBJAM2_API ASGJ_Timer_Watch : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGJ_Timer_Watch();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TimeForCake;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TimeForFirewood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ASGJ_Timer_Button* TimerButton;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartCakeTimer();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartFirewoodTimer();

	
	UFUNCTION()
	void OnTimerStopped();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	float CurrentMaxTime;
	UPROPERTY()
	float CurrentTime;

	UFUNCTION(BlueprintNativeEvent)
	void SetCurrentTime(float NewTime);
	UFUNCTION()
	void OnTimerStarted();
	UFUNCTION()
	void OnTimerRinged();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
