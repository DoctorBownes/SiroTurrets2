// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class SIROTURRETS2_API ABullet : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMesh;


	UPROPERTY(VisibleAnywhere)
		class UProjectileMovementComponent* ProjectTile;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* SphereCollision;

private:
	UFUNCTION()
		void OnCollisionHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	void FireInDirection(const FVector& ShootDirection);
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
