// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_QuestUtilities.h"

FText USGJ_QuestUtilities::GetRandomDialogue(const TArray<FSGJ_DialogueInfo>& DialogueArray, const TMap<FString, FSGJ_NameArray>& NameMap)
{
	if (DialogueArray.IsEmpty())
	{
		return FText();
	}

	FSGJ_DialogueInfo RandomDialogue = DialogueArray[FMath::RandRange(0, DialogueArray.Num() - 1)];

	if (RandomDialogue.DialogueType == ESGJ_DialogueType::DT_FirstSpeech)
	{
		TArray<FText> AdventurerNames = NameMap.FindRef(FString("Adventurer")).Names;
		FText RandomAdventurerName = AdventurerNames[FMath::RandRange(0, AdventurerNames.Num() - 1)];

		FFormatNamedArguments Args;
		Args.Add(FString("Adventurer"), RandomAdventurerName);
		return FText::Format(FTextFormat(RandomDialogue.DialogueFormat), Args);
	}
	return FText();
}
