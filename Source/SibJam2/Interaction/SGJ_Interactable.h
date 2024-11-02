// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SGJ_Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USGJ_Interactable : public UInterface
{
	GENERATED_BODY()
};

class SIBJAM2_API ISGJ_Interactable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable") 
	void InteractWith(AActor* Caller);
};
