#include "LapGate.h"
#include "Components/BoxComponent.h"

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

	EntryTrigger->OnComponentBeginOverlap.AddDynamic(this, &ALapGate::OnBeginOverlap);
	EntryTrigger->OnComponentEndOverlap.AddDynamic(this, &ALapGate::OnEndOverlap);
}

void ALapGate::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if Actor has Vehicle State
	// Increment counter
}

void ALapGate::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Check if Actor has Vehicle State
	// Increment counter
}