#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerVehicleState.h"
#include "MainPlayerController.generated.h"

UCLASS()
class ARCADERACER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<class UUserWidget> RaceHudAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* RaceHud = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State Objects")
	UPlayerVehicleState* VehicleState = nullptr;

protected:
	virtual void BeginPlay() override;
};
