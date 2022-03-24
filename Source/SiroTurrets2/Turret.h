// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "Turret.generated.h"

UCLASS()
class SIROTURRETS2_API ATurret : public APawn
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMesh;
		UPROPERTY(VisibleAnywhere)
		class UBoxComponent* BoxCollision;

private:
	void OnCollisionHit(UPrimitiveComponent* OnComponentHit, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


public:
	// Sets default values for this pawn's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
