// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_GoldPile.h"

#include "Hold/SGJ_HoldCoin.h"
#include "SibJam2/Game/SGJ_GameMode.h"
#include "SibJam2/Interaction/SGJ_Player_HoldComponent.h"

// Sets default values
ASGJ_GoldPile::ASGJ_GoldPile()
	: GoldToWin(300),
	  Gold(100)

{
}

void ASGJ_GoldPile::InteractWith_Implementation(AActor* Caller)
{
	if(!IsValid(Caller))
	{
		return;
	}
	
	auto* HoldComponent = Caller->GetComponentByClass<USGJ_Player_HoldComponent>();
	if (!IsValid(HoldComponent))
	{
		return;
	}

	auto* Coin = GetWorld()->SpawnActor<ASGJ_HoldCoin>(ASGJ_HoldCoin::StaticClass());
	HoldComponent->SetNewControlledActor(Coin);	
}

FText ASGJ_GoldPile::GetLookOnMessage_Implementation()
{
	return FText::Format(FTextFormat::FromString("{0} ({1})"), FText::FromString("Золото"), Gold);
}

int32 ASGJ_GoldPile::GetGold() const
{
	return Gold;
}

void ASGJ_GoldPile::SetGold(int32 NewGold)
{
	Gold = NewGold;
	if (Gold <= 0)
	{
		auto* GameMode = GetWorld()->GetAuthGameMode<ASGJ_GameMode>();
		if (!IsValid(GameMode))
		{
			return;
		}

		GameMode->OnGameLost();
		return;
	}

	if (Gold >= GoldToWin)
	{
		auto* GameMode = GetWorld()->GetAuthGameMode<ASGJ_GameMode>();
		if (!IsValid(GameMode))
		{
			return;
		}

		GameMode->OnGameWon();
	}
}
