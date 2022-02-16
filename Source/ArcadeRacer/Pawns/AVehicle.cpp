#include "AVehicle.h"

#include "WheeledVehicleMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAVehicle::AAVehicle()
{
	//PrimaryActorTick.bCanEverTick = true;

	//RootComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VehicleMesh"));
	
	// Create a spring arm component
	TPSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPSpringArm"));
	TPSpringArm->TargetOffset = FVector(0.f, 0.f, 200.f);
	TPSpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));
	TPSpringArm->SetupAttachment(GetMesh());
	TPSpringArm->TargetArmLength = 600.0f;
	TPSpringArm->bEnableCameraRotationLag = true;
	TPSpringArm->CameraRotationLagSpeed = 7.f;
	TPSpringArm->bInheritPitch = false;
	TPSpringArm->bInheritRoll = false;

	// Create camera component 
	TPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPCamera"));
	TPCamera->SetupAttachment(TPSpringArm, USpringArmComponent::SocketName);
	TPCamera->bUsePawnControlRotation = false;
	TPCamera->FieldOfView = 90.f;

	// Default Wheel Setup
	UWheeledVehicleMovementComponent* VehicleComponent = CastChecked<UWheeledVehicleMovementComponent>(GetVehicleMovement());

	check(VehicleComponent->WheelSetups.Num() == 4);

	VehicleComponent->WheelSetups[0].BoneName = FName("FL");
	VehicleComponent->WheelSetups[1].BoneName = FName("FR");

	VehicleComponent->WheelSetups[2].BoneName = FName("RR");
	VehicleComponent->WheelSetups[3].bDisableSteering = true;

	VehicleComponent->WheelSetups[3].BoneName = FName("RL");
	VehicleComponent->WheelSetups[3].bDisableSteering = true;
}

void AAVehicle::BeginPlay()
{
	Super::BeginPlay();
}

void AAVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

