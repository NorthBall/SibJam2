// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SibJam2/Interaction/SGJ_Interactable.h"
#include "SGJ_HeapBase.generated.h"

UCLASS()
class SIBJAM2_API ASGJ_HeapBase : public AActor, public ISGJ_Interactable
{
	GENERATED_BODY()
	
public:	
	ASGJ_HeapBase();

	virtual void InteractWith_Implementation(AActor* Caller) override;
	virtual FText GetLookOnMessage_Implementation() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetHeapCount(int32 NewCount);
	
protected:
	UPROPERTY(EditAnywhere)
	FText LookOnText;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> HeapItemClass;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 HeapCount;
};
