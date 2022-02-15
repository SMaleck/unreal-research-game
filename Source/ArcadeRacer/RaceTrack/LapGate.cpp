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
}

void ALapGate::BeginPlay()
{
	Super::BeginPlay();	

	EntryTrigger->OnComponentBeginOverlap.AddDynamic(this, &ALapGate::OnBeginOverlap);
	EntryTrigger->OnComponentEndOverlap.AddDynamic(this, &ALapGate::OnEndOverlap);
}

void ALapGate::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ALapGate::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}