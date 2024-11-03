// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_QuestUtilities.h"

FText USGJ_QuestUtilities::GetRandomDialogue(const TArray<FSGJ_DialogueInfo>& DialogueArray, const TMap<FString, FSGJ_NameArray>& NameMap, const ESGJ_DialogueType DialogueType)
{
	if (DialogueArray.IsEmpty())
	{
		return FText();
	}

	TArray<TArray<FSGJ_DialogueInfo>::ElementType> FilteredDialogueArr = DialogueArray.FilterByPredicate(
		[&DialogueType](const FSGJ_DialogueInfo& DInfo)
		{
			return DInfo.DialogueType == DialogueType;
		});

	FSGJ_DialogueInfo RandomDialogue = FilteredDialogueArr[FMath::RandRange(0, FilteredDialogueArr.Num() - 1)];

	TArray<FText> AdventurerNames = NameMap.FindRef(FString("Adventurer")).Names;
	FText RandomAdventurerName = AdventurerNames[FMath::RandRange(0, AdventurerNames.Num() - 1)];

	FFormatNamedArguments Args;
	Args.Add(FString("Adventurer"), RandomAdventurerName);
	
	return FText::Format(FTextFormat(RandomDialogue.DialogueFormat), Args);
}
