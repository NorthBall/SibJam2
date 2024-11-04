// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_Timer_Button.h"

#include "SGJ_Timer_Watch.h"

// Sets default values
ASGJ_Timer_Button::ASGJ_Timer_Button()
	: TimerState(ESGJ_TimerStates::Idle),
	  TimerWatch(nullptr)
{
}

void ASGJ_Timer_Button::InteractWith_Implementation(AActor* Caller)
{
	if (TimerState == ESGJ_TimerStates::Started
		|| TimerState == ESGJ_TimerStates::Ringed)
	{
		OnTimerEnded();
	}
}

FText ASGJ_Timer_Button::GetLookOnMessage_Implementation()
{
	if (TimerState == ESGJ_TimerStates::Started)
	{
		return FText::FromString(TEXT("Выключить таймер (досрочно)"));
	}

	if (TimerState == ESGJ_TimerStates::Ringed)
	{
		FText::FromString(TEXT("Выключить таймер (вовремя)"));
	}
	return FText();
}

void ASGJ_Timer_Button::OnTimerRinged_Implementation()
{
	TimerState = ESGJ_TimerStates::Ringed;
	OnTimerStateUpdated();
}

void ASGJ_Timer_Button::OnTimerStarted_Implementation()
{
	TimerState = ESGJ_TimerStates::Started;
	OnTimerStateUpdated();
}

void ASGJ_Timer_Button::OnTimerEnded_Implementation()
{
	TimerState = ESGJ_TimerStates::Idle;
	OnTimerStateUpdated();

	if (!IsValid(TimerWatch))
	{
		return;
	}

	TimerWatch->OnTimerStopped();
}