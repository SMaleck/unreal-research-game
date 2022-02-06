#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/*UPlayerVehicleState vState;
	VehicleState = &vState;*/

	if (!RaceHudAsset) {
		UE_LOG(LogTemp, Error, TEXT("No RaceHudAsset set"))
		return;
	}

	RaceHud = CreateWidget<UUserWidget>(this, RaceHudAsset);
	RaceHud->AddToViewport();
}