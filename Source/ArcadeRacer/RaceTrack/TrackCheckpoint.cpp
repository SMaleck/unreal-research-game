#include "RaceTrack/TrackCheckpoint.h"
#include "Components/BoxComponent.h"
#include "Pawns/VehicleStateComponent.h"

// Sets default values
ATrackCheckpoint::ATrackCheckpoint()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trrigger"));
	Trigger->SetupAttachment(GetRootComponent());

	Trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Trigger->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	Trigger->SetCollisionResponseToChannels(ECollisionResponse::ECR_Ignore);
	Trigger->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void ATrackCheckpoint::BeginPlay()
{
	Super::BeginPlay();
	
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ATrackCheckpoint::OnGateEnter);
}

void ATrackCheckpoint::OnGateEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UActorComponent* component = OtherActor->GetComponentByClass(UVehicleStateComponent::StaticClass());
	if(component)
	{
		UVehicleStateComponent* State = CastChecked<UVehicleStateComponent>(component);
		State->EnterCheckpoint(CheckpointId);
	}
}