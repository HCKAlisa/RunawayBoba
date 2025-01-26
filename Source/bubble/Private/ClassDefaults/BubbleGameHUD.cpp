// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassDefaults/BubbleGameHUD.h"

#include "BubbleGameplayTagsList.h"
#include "UITag.h"
#include "UI/BaseUILayout.h"

void ABubbleGameHUD::BeginPlay()
{
	Super::BeginPlay();
	PushHUD();
}

void ABubbleGameHUD::PushHUD()
{
	if (IsValid(RootLayer) && PlayerInGameHUD)
	{
		RootLayer->PushWidgetToLayer(FUITag::TryConvert(BubbleGameplayTags::TAG_UI_LAYER_GAME), PlayerInGameHUD);
	}
}
