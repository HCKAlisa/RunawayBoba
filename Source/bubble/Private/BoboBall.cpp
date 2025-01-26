// Fill out your copyright notice in the Description page of Project Settings.


#include "BoboBall.h"

#include "Components/SphereComponent.h"

// Sets default values
ABoboBall::ABoboBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->SetSimulatePhysics(true);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SphereComponent);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);



	DirtLevel=0;
	MaxDirtLevel = 100;
	
}

void ABoboBall::AddDirt(float DirtAdded)
{
	const float OldDirtPercent = DirtLevel/MaxDirtLevel;
	DirtLevel =  FMath::Clamp(DirtLevel + DirtAdded, 0, MaxDirtLevel);
	const float NewDirtPercent = DirtLevel/MaxDirtLevel;
	if(DirtChange.IsBound())
	{
		DirtChange.Broadcast(OldDirtPercent,NewDirtPercent);
	}
	if(FMath::IsNearlyEqual(DirtLevel,MaxDirtLevel))
	{
		if(GameOverCon.IsBound())
		{
			GameOverCon.Broadcast(false,DirtLevel);
		}
	}
}

void ABoboBall::GameOverFunction()
{
	if(GameOverCon.IsBound())
	{
		GameOverCon.Broadcast(true,DirtLevel);
	}
}

// Called when the game starts or when spawned
void ABoboBall::BeginPlay()
{
	Super::BeginPlay();
	DirtLevel=0;
}

// Called every frame
void ABoboBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

