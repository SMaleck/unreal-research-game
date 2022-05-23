


#include "ArcadeRacerGameState.h"

void AArcadeRacerGameState::RegisterCheckpoint(ATrackCheckpoint* checkpoint)
{
	if(!Checkpoints.Contains(checkpoint))
	{
		Checkpoints.Add(checkpoint);
		Checkpoints.Sort();
	}
}
