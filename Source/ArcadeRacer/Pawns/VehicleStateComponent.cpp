#include "VehicleStateComponent.h"
#include "WheeledVehicleMovementComponent.h"
#include "Math/UnrealMathUtility.h"

UVehicleStateComponent::UVehicleStateComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UVehicleStateComponent::BeginPlay()
{
	Super::BeginPlay();

	GateEnterCount = 0;
	GateExitCount = 0;
	CompletedLaps = 0;
	LapTimeSeconds = 0;
	
	MovementComponent = GetOwner()->FindComponentByClass<UWheeledVehicleMovementComponent>();
}

void UVehicleStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SetSpeed(MovementComponent->GetForwardSpeed());
	LapTimeSeconds += DeltaTime;
}

void UVehicleStateComponent::SetSpeed(float unitsPerSecond)
{
	SpeedUps = unitsPerSecond;
	SpeedKmh = (SpeedUps * 3.6f) / 100;
}

void UVehicleStateComponent::EnterGate()
{
	if(GateEnterCount == GateExitCount)
	{
		GateEnterCount++;
	}
}

void UVehicleStateComponent::ExitGate()
{
	// ToDo Verify here, that we actually passed all checkpoints
	if(GateEnterCount > GateExitCount)
	{
		GateExitCount++;
		CompletedLaps++;
		LapTimeSeconds = 0;
		LastCheckpointId = -1;
	}
}

void UVehicleStateComponent::EnterCheckpoint(int32 checkpointId)
{
	if(LastCheckpointId == checkpointId - 1)
	{
		LastCheckpointId = checkpointId;
	}
}

