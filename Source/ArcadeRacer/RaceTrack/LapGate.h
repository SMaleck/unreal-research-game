#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LapGate.generated.h"

UCLASS()
class ARCADERACER_API ALapGate : public AActor
{
	GENERATED_BODY()
	
public:	
	ALapGate();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
