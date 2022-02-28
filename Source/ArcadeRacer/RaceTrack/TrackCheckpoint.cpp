


#include "RaceTrack/TrackCheckpoint.h"

// Sets default values
ATrackCheckpoint::ATrackCheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrackCheckpoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackCheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

