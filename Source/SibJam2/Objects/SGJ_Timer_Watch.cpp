// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_Timer_Watch.h"

#include "SGJ_Timer_Button.h"

ASGJ_Timer_Watch::ASGJ_Timer_Watch()
	: TimeForCake(0.f),
	  TimeForFirewood(0.f),
	  TimerButton(nullptr),
	  CurrentMaxTime(0.f),
	  CurrentTime(0.f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASGJ_Timer_Watch::StartCakeTimer_Implementation()
{
	SetCurrentTime(0.f);
	CurrentMaxTime = TimeForCake;

	OnTimerStarted();
}

void ASGJ_Timer_Watch::StartFirewoodTimer_Implementation()
{
	SetCurrentTime(0.f);
	CurrentMaxTime = TimeForFirewood;

	OnTimerStarted();
}

void ASGJ_Timer_Watch::BeginPlay()
{
	Super::BeginPlay();
}

void ASGJ_Timer_Watch::SetCurrentTime_Implementation(float NewTime)
{
	CurrentTime = NewTime;
}

void ASGJ_Timer_Watch::OnTimerStarted()
{
	if (!IsValid(TimerButton))
	{
		return;
	}

	TimerButton->OnTimerStarted();
}

void ASGJ_Timer_Watch::OnTimerRinged()
{
	if (!IsValid(TimerButton))
	{
		return;
	}

	TimerButton->OnTimerRinged();
}

void ASGJ_Timer_Watch::OnTimerStopped()
{
	CurrentMaxTime = 0.f;
}

void ASGJ_Timer_Watch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::IsNearlyZero(CurrentMaxTime))
	{
		return;
	}

	if (CurrentTime < CurrentMaxTime
		&& CurrentTime + DeltaTime > CurrentMaxTime)
	{
		OnTimerRinged();
	}

	SetCurrentTime(CurrentTime + DeltaTime);
}
