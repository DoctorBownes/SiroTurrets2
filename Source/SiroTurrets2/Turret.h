// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GameFramework/Pawn.h"
#include "Turret.generated.h"

UCLASS()
class SIROTURRETS2_API ATurret : public APawn
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMesh;

private:
	TSubclassOf<AEnemy> classToFind;
	TArray<AActor*> foundEnemies;
	AEnemy* targetEnemy;
	float distance = 1000.0f;

public:
	// Sets default values for this pawn's properties
	ATurret();

	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnCollisionHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
