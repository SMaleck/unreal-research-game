// Copyright Epic Games, Inc. All Rights Reserved.

#include "arcade_racerGameMode.h"
#include "arcade_racerPawn.h"
#include "arcade_racerHud.h"

Aarcade_racerGameMode::Aarcade_racerGameMode()
{
	DefaultPawnClass = Aarcade_racerPawn::StaticClass();
	HUDClass = Aarcade_racerHud::StaticClass();
}
