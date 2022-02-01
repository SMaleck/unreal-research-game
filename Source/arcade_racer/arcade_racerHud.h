// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "arcade_racerHud.generated.h"


UCLASS(config = Game)
class Aarcade_racerHud : public AHUD
{
	GENERATED_BODY()

public:
	Aarcade_racerHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
