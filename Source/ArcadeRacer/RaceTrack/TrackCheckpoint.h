

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackCheckpoint.generated.h"

UCLASS()
class ARCADERACER_API ATrackCheckpoint : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrackCheckpoint();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Checkpoints")
	int CheckpointId = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Checkpoints")
	class UBoxComponent* Trigger = nullptr;
		
protected:
	virtual void BeginPlay() override;

private:
	void OnGateEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
