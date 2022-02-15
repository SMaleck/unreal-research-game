#include "RaceTrack/LapGate.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALapGate::ALapGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultObject<USceneComponent>("RootComponent");

}

// Called when the game starts or when spawned
void ALapGate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALapGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

