// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_Hold_Sword.h"

ASGJ_Hold_Sword::ASGJ_Hold_Sword()
{
}

void ASGJ_Hold_Sword::SetRarity_Implementation(const FText& NewRarity)
{
	Rarity = NewRarity;
}

FText ASGJ_Hold_Sword::GetRarity() const
{
	return Rarity;
}