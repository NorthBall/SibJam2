// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_QuestType.h"

#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameStateBase.h"
#include "SibJam2/Objects/SGJ_GoldPile.h"
#include "SibJam2/Objects/SGJ_QuestResultBoard.h"

USGJ_QuestType::USGJ_QuestType()
	: CostPerItem(0),
	  ForgivenCalcError(2),
	  ChosenCount(0),
	  RealCount(0),
	  Adventurer(nullptr),
	  GoldSource(nullptr),
	  ResultBoard(nullptr),
	  BoardIncomeName(FText::FromString(TEXT("Прибыль от деятельности")))

{
}

void USGJ_QuestType::OnQuestGivenToAdventurer()
{
}

void USGJ_QuestType::OnQuestCompleted(FText CustomPaymentName)
{
	if (IsValid(GoldSource) && CustomPaymentName.IsEmpty())
	{
		int32 ChangeInGold = (ForgivenCalcError - FMath::Abs(RealCount - ChosenCount)) * CostPerItem;
		GoldSource->SetGold(GoldSource->GetGold() + ChangeInGold);
	}

	if (IsValid(ResultBoard))
	{
		int32 Income = (ForgivenCalcError + RealCount) * CostPerItem;
		TArray<FText> IncomeArray;
		IncomeArray.Add(FText::Format(FTextFormat::FromString("{0} ({1})"), BoardIncomeName, Income));
		ResultBoard->IncomeArray = IncomeArray;

		TArray<FText> ExpenseArray;
		if (CustomPaymentName.IsEmpty())
		{
			int32 Payment = ChosenCount * CostPerItem;
			ExpenseArray.Add(FText::Format(FTextFormat::FromString("{0} ({1})"), BoardPayName, Payment));
		}
		else
		{
			ExpenseArray.Add(CustomPaymentName);
		}

		int32 Penalty = (RealCount - ChosenCount) * CostPerItem;
		if (Penalty > 0)
		{
			ExpenseArray.Add(FText::Format(FTextFormat::FromString("{0} ({1})"), BoardPenaltyName, Income));
		}

		ResultBoard->ExpenseArray = ExpenseArray;
		ResultBoard->UpdateWidget();
	}
}

AActor* USGJ_QuestType::GetGameMode() const
{
	if(!IsValid(GetWorld()))
	{
		return nullptr;
	}

	return GetWorld()->GetAuthGameMode();
}

AActor* USGJ_QuestType::GetGameState() const
{
	if(!IsValid(GetWorld()))
	{
		return nullptr;
	}

	return GetWorld()->GetGameState();
}

bool USGJ_QuestType::GiveQuestToAdventurer_Implementation(const FText& QuestDescription, FText& ErrorDescription)
{
	ErrorDescription = FText::FromString(TEXT("Неправильный тип квеста"));
	return false;
}
