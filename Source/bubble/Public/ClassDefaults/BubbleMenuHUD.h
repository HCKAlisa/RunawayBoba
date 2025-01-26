// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BubbleHUDBase.h"
#include "BubbleMenuHUD.generated.h"

class UCommonActivatableWidget;
/**
 * 
 */
UCLASS()
class BUBBLE_API ABubbleMenuHUD : public ABubbleHUDBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCommonActivatableWidget> MainMenu;
};
