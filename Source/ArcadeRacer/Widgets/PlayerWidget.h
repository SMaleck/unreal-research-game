#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Player/MainPlayerController.h"
#include "PlayerWidget.generated.h"

UCLASS()
class ARCADERACER_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetPlayer(AMainPlayerController* player);

private:
	AMainPlayerController* Player = nullptr;
};
