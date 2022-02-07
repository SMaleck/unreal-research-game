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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<class UUserWidget> PlayerHudAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD")
	UUserWidget* PlayerHud = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State Objects")
	UPlayerVehicleState* VehicleState = nullptr;

protected:
	virtual void BeginPlay() override;
};
