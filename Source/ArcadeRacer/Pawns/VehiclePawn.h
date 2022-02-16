// AWheeledVehicle is deprecated because PhysX is deprecated
// However Chaos was still experimental at time of project creation, so here we are 

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

UCLASS()
class ARCADERACER_API AVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	AVehiclePawn();

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* TPSpringArm = nullptr;

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TPCamera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UVehicleStateComponent* VehicleState = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
