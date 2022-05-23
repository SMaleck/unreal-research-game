#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RaceTrack/TrackCheckpoint.h"
#include "ArcadeRacerGameState.generated.h"

UCLASS()
class ARCADERACER_API AArcadeRacerGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void RegisterCheckpoint(ATrackCheckpoint* checkpoint);

private:
	UPROPERTY()
	TArray<ATrackCheckpoint*> Checkpoints;
	
};
