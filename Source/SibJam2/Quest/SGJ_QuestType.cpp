// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_QuestType.h"

USGJ_QuestType::USGJ_QuestType()
	: ChosenCount(0),
	  Adventurer(nullptr)
{
}

void USGJ_QuestType::OnQuestGivenToAdventurer()
{
}

bool USGJ_QuestType::GiveQuestToAdventurer_Implementation(const FText& QuestDescription, FText& ErrorDescription)
{
	ErrorDescription = FText::FromString("Неправильный тип квеста");
	return false;
}
