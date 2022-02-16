// AWheeledVehicle is deprecated because PhysX is deprecated
// However Chaos was still experimental at time of project creation, so here we are 

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "AVehicle.generated.h"

UCLASS()
class ARCADERACER_API AAVehicle : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	AAVehicle();

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* TPSpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCameraComponent* TPCamera = nullptr;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
