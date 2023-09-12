// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerA.h"
#include <Blueprint/WidgetLayoutLibrary.h>

// Sets default values
APlayerA::APlayerA()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerA::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerA::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlayerA::Jump);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerA::MoveForward);
}

void APlayerA::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerA::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}