// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BubbleHUDBase.generated.h"

class UBaseUILayout;
/**
 * 
 */
UCLASS()
class BUBBLE_API ABubbleHUDBase : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBaseUILayout> BaseUILayer;

	UPROPERTY(BlueprintReadWrite, Category="RootUILayer")
	UBaseUILayout* RootLayer;

	UFUNCTION(BlueprintCallable)
	UBaseUILayout* ReturnRootLayer(); 

	virtual void BeginPlay() override;
};
