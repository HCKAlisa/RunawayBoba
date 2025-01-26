// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BubbleHUDBase.h"
#include "BubbleGameHUD.generated.h"

class UCommonActivatableWidget;
/**
 * 
 */
UCLASS()
class BUBBLE_API ABubbleGameHUD : public ABubbleHUDBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UCommonActivatableWidget> PlayerInGameHUD;

protected:

	UFUNCTION(BlueprintCallable)
	void PushHUD();
	
};
