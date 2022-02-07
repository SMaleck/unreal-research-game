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

	PlayerController = Cast<AMainPlayerController>(GetOwner());
	if (!PlayerController) {
		UE_LOG(LogTemp, Error, TEXT("AMainPlayerController not found!"))
		return;
	}

	VehicleComponent = PlayerController->AcknowledgedPawn->FindComponentByClass<UWheeledVehicleMovementComponent>();
	if (!VehicleComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("UWheeledVehicleMovementComponent not found!"))
		return;
	}	
}


// Called every frame
void UPlayerVehicleStateRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Error, TEXT("UWheeledVehicleMovementComponent not found!"))
	PlayerController->VehicleState->SpeedUnitsPerSecond = VehicleComponent->GetForwardSpeed();
}

