#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Pawns/VehicleStateComponent.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	VehicleState = AcknowledgedPawn->FindComponentByClass<UVehicleStateComponent>();

	if (!PlayerHudAsset) {
		UE_LOG(LogTemp, Error, TEXT("No RaceHudAsset set"))
		return;
	}

	PlayerHud = CreateWidget<UUserWidget>(this, PlayerHudAsset);
	PlayerHud->AddToViewport();
}
