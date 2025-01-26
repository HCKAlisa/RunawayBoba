// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleHUDBase.h"

#include "UI/BaseUILayout.h"

UBaseUILayout* ABubbleHUDBase::ReturnRootLayer()
{
	return RootLayer;
}

void ABubbleHUDBase::BeginPlay()
{
	Super::BeginPlay();
	if(!BaseUILayer)
	{
		return;
	}
	if (IsValid(GetOwningPlayerController()))
	{
		RootLayer = Cast<UBaseUILayout>(CreateWidget(GetOwningPlayerController(), BaseUILayer)) ;
		if(IsValid(RootLayer))
		{
			//DebugUse
			//GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, RootLayer->GetName());
			RootLayer->AddToViewport();
			
		}
	};
}
