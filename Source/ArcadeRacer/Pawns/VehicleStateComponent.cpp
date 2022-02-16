#include "VehicleStateComponent.h"
#include "WheeledVehicleMovementComponent.h"

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
	
	MovementComponent = GetOwner()->FindComponentByClass<UWheeledVehicleMovementComponent>();
}

void UVehicleStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SetSpeed(MovementComponent->GetForwardSpeed());
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
	if(GateEnterCount > GateExitCount)
	{
		GateExitCount++;
		CompletedLaps++;
	}
}

