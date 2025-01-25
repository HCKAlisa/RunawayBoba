// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseUILayout.h"

#include "BubbleGameplayTagsList.h"
#include "UITag.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

void UBaseUILayout::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Layer.Add(FUITag::TryConvert(BubbleGameplayTags::TAG_UI_LAYER_GAME), GameStack);
	Layer.Add(FUITag::TryConvert(BubbleGameplayTags::TAG_UI_LAYER_MENU), MenuStack);
	Layer.Add(FUITag::TryConvert(BubbleGameplayTags::TAG_UI_LAYER_POPUP), PopUpStack);
}

void UBaseUILayout::RegisterLayer(FUITag LayerTag, TObjectPtr<UCommonActivatableWidgetContainerBase> LayerStack)
{
	Layer.Add(LayerTag, LayerStack);
}

UBaseUILayout::UBaseUILayout()
{
	bAutoActivate =true;
	bSupportsActivationFocus = true;
}

TOptional<FUIInputConfig> UBaseUILayout::GetDesiredInputConfig() const
{
	FUIInputConfig InputConfig
	{
		ECommonInputMode::All,
		EMouseCaptureMode::CapturePermanently
	};
	return InputConfig;
	
}

void UBaseUILayout::PushWidgetToLayer(FUITag LayerTag, TSubclassOf<UCommonActivatableWidget> Widget)
{
	
	if (Layer.Find(LayerTag))
	{
		TObjectPtr<UCommonActivatableWidgetContainerBase> LayerToPush = Layer.FindRef(LayerTag);
		
		if (IsValid(LayerToPush))
		{
			TObjectPtr<UCommonActivatableWidget> CurrentWidget = LayerToPush->GetActiveWidget();
			if (!IsValid(CurrentWidget))
			{
				LayerToPush->AddWidget<UCommonActivatableWidget>(Widget);
				GetActivatedWidgetInLayer(LayerTag);
				return;
			}

			if (!CurrentWidget.IsA(Widget))
			{
				LayerToPush->AddWidget<UCommonActivatableWidget>(Widget);
				GetActivatedWidgetInLayer(LayerTag);
				return;
			}
		}
		
	};
}

UCommonActivatableWidget* UBaseUILayout::GetActivatedWidgetInLayer(FUITag LayerTag)
{
	if (Layer.Find(LayerTag))
	{
		TObjectPtr<UCommonActivatableWidgetContainerBase> LayerToSearch = Layer.FindRef(LayerTag);
		
		if (IsValid(LayerToSearch))
		{
			UCommonActivatableWidget* CurrentWidget = LayerToSearch->GetActiveWidget();
			//GEngine->AddOnScreenDebugMessage(0, 10, FColor::Green, CurrentWidget->GetName());
			return CurrentWidget;
		}
	}
		//GEngine->AddOnScreenDebugMessage(0, 10, FColor::Red, "None");
		return nullptr;
}