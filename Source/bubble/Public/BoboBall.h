// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoboBall.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDirtChange , float ,OldPercent,float,NewPercent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameOverCon ,bool ,bWin,float,DirtPercent);
UCLASS()
class BUBBLE_API ABoboBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoboBall();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float DirtLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float MaxDirtLevel;

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FDirtChange DirtChange;


	UFUNCTION(BlueprintCallable)
	void AddDirt(float DirtAdded);

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FGameOverCon GameOverCon;

	UFUNCTION(BlueprintCallable)
	void GameOverFunction();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
