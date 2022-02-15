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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Visuals")
	class UStaticMeshComponent* GateMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Triggers")
	class UBoxComponent* EntryTrigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Triggers")
	class UBoxComponent* ExitTrigger;

private:
	void SetupTriggers();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
