#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	VehicleState = NewObject<UVehicleState>(this);

	if (!PlayerHudAsset) {
		UE_LOG(LogTemp, Error, TEXT("No RaceHudAsset set"))
		return;
	}

	PlayerHud = CreateWidget<UUserWidget>(this, PlayerHudAsset);
	PlayerHud->AddToViewport();
}