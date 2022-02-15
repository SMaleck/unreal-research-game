#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerVehicleState.generated.h"

UCLASS()
class ARCADERACER_API UPlayerVehicleState : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float SpeedUnitsPerSecond;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int GateEnterCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int GateExitCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int CompletedLaps;
};
