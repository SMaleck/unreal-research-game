#include "ArcadeRacerGameMode.h"
#include "GameStates/ArcadeRacerGameState.h"

AArcadeRacerGameMode::AArcadeRacerGameMode()
{
	GameStateClass = AArcadeRacerGameState::StaticClass();
}