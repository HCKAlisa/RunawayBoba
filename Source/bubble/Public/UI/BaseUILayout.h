// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UITag.h"
#include "BaseUILayout.generated.h"

/**
 * 
 */
class UCommonActivatableWidgetContainerBase;
class UCommonActivatableWidgetStack;

UCLASS()
class BUBBLE_API UBaseUILayout : public UCommonActivatableWidget
{
 GENERATED_BODY()

public:
	UBaseUILayout();

	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
	
	UFUNCTION(BlueprintCallable)
	void PushWidgetToLayer(FUITag LayerTag, TSubclassOf<UCommonActivatableWidget> Widget);

	UFUNCTION(BlueprintCallable)
	UCommonActivatableWidget* GetActivatedWidgetInLayer(FUITag LayerTag);

	TMap<FUITag, TObjectPtr<UCommonActivatableWidgetContainerBase>> Layer;

	UPROPERTY(BlueprintReadOnly, Category="Stack", meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> GameStack;

	UPROPERTY(BlueprintReadOnly, Category="Stack", meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> MenuStack;

	UPROPERTY(BlueprintReadOnly, Category="Stack", meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> PopUpStack;
	
private:
	virtual void NativeOnInitialized() override;
	
	void RegisterLayer(FUITag LayerTag, TObjectPtr<UCommonActivatableWidgetContainerBase> LayerStack);
	
};