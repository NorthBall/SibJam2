// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_HeapBase.h"

#include "SibJam2/Interaction/SGJ_Player_HoldComponent.h"

ASGJ_HeapBase::ASGJ_HeapBase()
{
}

void ASGJ_HeapBase::InteractWith_Implementation(AActor* Caller)
{
	if(!IsValid(Caller))
	{
		return;
	}

	auto* HoldComponent = Caller->GetComponentByClass<USGJ_Player_HoldComponent>();
	if(!IsValid(HoldComponent))
	{
		return;
	}

	AActor* HeapItem = GetWorld()->SpawnActor(HeapItemClass);
	HoldComponent->SetNewControlledActor(HeapItem);
}

FText ASGJ_HeapBase::GetLookOnMessage_Implementation()
{
	return LookOnText;
}

void ASGJ_HeapBase::SetHeapCount_Implementation(int32 NewCount)
{
	if(NewCount < 0)
	{
		return;
	}
	
	HeapCount = NewCount;
}

