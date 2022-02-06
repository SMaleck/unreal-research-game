// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WheeledVehicleMovementComponent.h"
#include "MainPlayerController.h"
#include "PlayerVehicleStateRecorder.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADERACER_API UPlayerVehicleStateRecorder : public UActorComponent
{
	GENERATED_BODY()

private:
	AMainPlayerController* PlayerController = nullptr;
	UWheeledVehicleMovementComponent* VehicleComponent = nullptr;

public:	
	// Sets default values for this component's properties
	UPlayerVehicleStateRecorder();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
