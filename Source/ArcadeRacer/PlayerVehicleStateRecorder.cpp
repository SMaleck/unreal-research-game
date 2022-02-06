// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerVehicleStateRecorder.h"

// Sets default values for this component's properties
UPlayerVehicleStateRecorder::UPlayerVehicleStateRecorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerVehicleStateRecorder::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* player = GetWorld()->GetFirstPlayerController();

	VehicleComponent = player->AcknowledgedPawn->FindComponentByClass<UWheeledVehicleMovementComponent>();
	if (!VehicleComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("No VehicleComponent found on Player %s"), *player->GetName())
	}	
}


// Called every frame
void UPlayerVehicleStateRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

