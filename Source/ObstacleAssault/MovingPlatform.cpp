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


}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlataform(DeltaTime);
}

void AMovingPlatform::MovePlataform(float DeltaTime)
{
	if (timePast <= duration)
	{
		if (movingRight)
			CubePosition.Y += 1;
		else
			CubePosition.Y -= 1;

		SetActorLocation(CubePosition);
		timePast += DeltaTime;

	}
	else {
		timePast = 0;
		movingRight = !movingRight;
	}
}

