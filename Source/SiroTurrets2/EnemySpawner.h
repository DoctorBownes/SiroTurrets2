// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SIROTURRETS2_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

private:
	float timer = 0.5f;
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class ASiroTurrets2GameModeBase* GameBase;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
