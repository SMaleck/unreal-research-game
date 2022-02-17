#include "LapGate.h"
#include "Components/BoxComponent.h"
#include "Pawns/VehicleStateComponent.h"

// Sets default values
ALapGate::ALapGate()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	GateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gate"));
	GateMesh->SetupAttachment(GetRootComponent());

	EntryTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("EntryTrrigger"));
	EntryTrigger->SetupAttachment(GetRootComponent());
	
	ExitTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ExitTrigger"));
	ExitTrigger->SetupAttachment(GetRootComponent());
	
	SetupTrigger(EntryTrigger);
	SetupTrigger(ExitTrigger);
}

void ALapGate::SetupTrigger(UBoxComponent* trigger)
{
	trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	trigger->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	trigger->SetCollisionResponseToChannels(ECollisionResponse::ECR_Ignore);
	trigger->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void ALapGate::BeginPlay()
{
	Super::BeginPlay();	

	EntryTrigger->OnComponentBeginOverlap.AddDynamic(this, &ALapGate::OnGateEnter);
	ExitTrigger->OnComponentBeginOverlap.AddDynamic(this, &ALapGate::OnGateExit);
}

void ALapGate::OnGateEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UActorComponent* component = OtherActor->GetComponentByClass(UVehicleStateComponent::StaticClass());
	if(component)
	{
		UVehicleStateComponent* State = CastChecked<UVehicleStateComponent>(component);
		State->EnterGate();
	}
}

void ALapGate::OnGateExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UActorComponent* component = OtherActor->GetComponentByClass(UVehicleStateComponent::StaticClass());
	if(component)
	{
		UVehicleStateComponent* State = CastChecked<UVehicleStateComponent>(component);
		State->ExitGate();
	}
}