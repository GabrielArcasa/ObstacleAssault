// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();


	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay : %s"), *Name);
}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	if(WaitToStart > 0)
	WaitToStart -= DeltaTime;

	if (WaitToStart <= 0) 
	{
		MovePlatform(DeltaTime);
		RotatePlatform(DeltaTime);
	}

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MaxDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else 
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	if (CanRotate)
		AddActorWorldRotation(RotationVelocity * DeltaTime);
		//AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return   GetDistanceMoved() >= MaxDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
