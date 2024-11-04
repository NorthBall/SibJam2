// Fill out your copyright notice in the Description page of Project Settings.


#include "SGJ_Player_HoldComponent.h"

USGJ_Player_HoldComponent::USGJ_Player_HoldComponent()
{
}

bool USGJ_Player_HoldComponent::SetNewControlledActor(AActor* NewActor, bool ShouldDestroy)
{
	if (ControlledActor == NewActor)
	{
		return false;
	}

	if(IsValid(ControlledActor))
	{
		if(ShouldDestroy)
		{
			ControlledActor->Destroy();
		} else
		{
			ControlledActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		}
	}
	
	ControlledActor = NewActor;

	if (IsValid(ControlledActor))
	{
		ControlledActor->AttachToComponent(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), NAME_None);
	}

	return true;
	
}

AActor* USGJ_Player_HoldComponent::GetControlledActor() const
{
	return ControlledActor;
}
