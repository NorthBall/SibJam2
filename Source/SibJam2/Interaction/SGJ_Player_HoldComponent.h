// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SGJ_Player_HoldComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIBJAM2_API USGJ_Player_HoldComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USGJ_Player_HoldComponent();

	UFUNCTION(BlueprintCallable)
	bool SetNewControlledActor(AActor* NewActor, bool ShouldDestroy=true);
	UFUNCTION(BlueprintPure)
	AActor* GetControlledActor() const;

protected:
	UPROPERTY()
	AActor* ControlledActor;		
};
