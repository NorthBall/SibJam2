// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_QuestResultBoard.h"

ASGJ_QuestResultBoard::ASGJ_QuestResultBoard()
{
}

void ASGJ_QuestResultBoard::InteractWith_Implementation(AActor* Caller)
{
}

FText ASGJ_QuestResultBoard::GetLookOnMessage_Implementation()
{
	return FText::FromString("Результаты квеста");
}

