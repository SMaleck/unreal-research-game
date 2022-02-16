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
	UE_LOG(LogTemp, Warning, TEXT("Gate SETUP SUCCESS"))
	EntryTrigger->OnComponentBeginOverlap.AddDynamic(this, &ALapGate::OnBeginOverlap);
	EntryTrigger->OnComponentEndOverlap.AddDynamic(this, &ALapGate::OnEndOverlap);
}

void ALapGate::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Gate ENTER"))
	UActorComponent* component = OtherActor->GetComponentByClass(UVehicleStateComponent::StaticClass());
	if(component)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gate ENTER SUCCESS"))
		UVehicleStateComponent* State = CastChecked<UVehicleStateComponent>(component);
		State->EnterGate();
	}
}

void ALapGate::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Gate EXIT"))
	UActorComponent* component = OtherActor->GetComponentByClass(UVehicleStateComponent::StaticClass());
	if(component)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gate EXIT SUCCESS"))
		UVehicleStateComponent* State = CastChecked<UVehicleStateComponent>(component);
		State->ExitGate();
	}
}