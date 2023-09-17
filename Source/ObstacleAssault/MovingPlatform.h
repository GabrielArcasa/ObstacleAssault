// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

private:
	UPROPERTY(EditAnywhere, Category = "Platform|Moving")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Platform|Moving")
	float MaxDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Platform|Moving")
	float WaitToStart = 0;

	UPROPERTY(VisibleAnywhere, Category = "Platform|Moving")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Platform|Rotation")
	FRotator RotationVelocity;
	UPROPERTY(EditAnywhere, Category = "Platform|Rotation")
	bool CanRotate = false;
public:
	// Construtor.
	AMovingPlatform();

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
