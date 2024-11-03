#pragma once

#include "CoreMinimal.h"
#include "SGJ_QuestStructs.generated.h"

UENUM(BlueprintType)
enum ESGJ_DialogueType
{
	DT_FirstSpeech UMETA(DisplayName = "FirstSpeach"),
	DT_GotQuest UMETA(DisplayName = "GotQuest"),
	DT_QuestDone UMETA(DisplayName = "QuestDone"),
	DT_SayBye UMETA(DisplayName = "SayBye"),
};

USTRUCT(BlueprintType)
struct FSGJ_DialogueInfo
{
	GENERATED_BODY()

	FSGJ_DialogueInfo()
		:DialogueType(ESGJ_DialogueType::DT_FirstSpeech)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DialogueFormat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ESGJ_DialogueType> DialogueType;
};

USTRUCT(BlueprintType)
struct FSGJ_NameArray
{
	GENERATED_BODY()

	FSGJ_NameArray()
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> Names;
};

