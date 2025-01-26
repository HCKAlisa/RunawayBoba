// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassDefaults/BubbleMenuHUD.h"

#include "BubbleGameplayTagsList.h"
#include "CommonActivatableWidget.h"
#include "UITag.h"
#include "UI/BaseUILayout.h"

void ABubbleMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	if (RootLayer && MainMenu)
	{
		RootLayer->PushWidgetToLayer(FUITag::TryConvert(BubbleGameplayTags::TAG_UI_LAYER_MENU), MainMenu);
	}
}
