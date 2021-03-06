#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VehicleStateComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ARCADERACER_API UVehicleStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UVehicleStateComponent();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float SpeedUps; // Units per Second

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float SpeedKmh; // Km per Hour

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float LapTimeSeconds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int GateEnterCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int GateExitCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int CompletedLaps;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 LastCheckpointId;

	virtual void BeginPlay() override;
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);

	UFUNCTION()
	void SetSpeed(float unitsPerSecond);
	
	UFUNCTION()
	void EnterGate();

	UFUNCTION()
	void ExitGate();

	void EnterCheckpoint(int32 checkpointId);

private:
	class UWheeledVehicleMovementComponent* MovementComponent = nullptr;
};
