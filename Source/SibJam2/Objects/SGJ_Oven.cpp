// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_Oven.h"

#include "SGJ_Timer_Watch.h"
#include "Hold/SGJ_Hold_CakeBlank.h"
#include "Hold/SGJ_Hold_Firewood.h"
#include "SibJam2/Interaction/SGJ_Player_HoldComponent.h"

ASGJ_Oven::ASGJ_Oven()
	:TimerWatch(nullptr)
{
}

void ASGJ_Oven::InteractWith_Implementation(AActor* Caller)
{
	if(!IsValid(Caller))
	{
		return;
	}

	auto* HoldComponent = Caller->GetComponentByClass<USGJ_Player_HoldComponent>();
	if(!IsValid(HoldComponent))
	{
		return;
	}

	AActor* HeldItem = HoldComponent->GetControlledActor();
	if(!IsValid(HeldItem))
	{
		return;
	}


	if(HeldItem->IsA<ASGJ_Hold_CakeBlank>())
	{
		HoldComponent->SetNewControlledActor(nullptr);
		BakeCake();
		return;
	}

	if (HeldItem->IsA<ASGJ_Hold_Firewood>())
	{
		HoldComponent->SetNewControlledActor(nullptr);
		BakeFirewood();
		return;
	}
}

FText ASGJ_Oven::GetLookOnMessage_Implementation()
{
	return FText::FromString(TEXT("Бросить в печь"));
}

void ASGJ_Oven::BakeCake_Implementation()
{
	if(!IsValid(TimerWatch))
	{
		return;
	}

	TimerWatch->StartCakeTimer();
}

void ASGJ_Oven::BakeFirewood_Implementation()
{
	if(!IsValid(TimerWatch))
	{
		return;
	}

	TimerWatch->StartFirewoodTimer();
}

