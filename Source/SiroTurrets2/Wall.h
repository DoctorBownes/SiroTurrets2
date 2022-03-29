// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class SIROTURRETS2_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

private:

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* BoxComponent;

	int health = 3;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class ASiroTurrets2GameModeBase* GameBase;

	void SpacePressed();

	UFUNCTION()
	void OnCollisionHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
