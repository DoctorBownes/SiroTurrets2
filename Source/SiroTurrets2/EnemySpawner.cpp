// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "SiroTurrets2GameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GameBase = Cast<ASiroTurrets2GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	FTimerHandle TimerHandler = FTimerHandle();
	GetGameInstance()->GetTimerManager().SetTimer(TimerHandler, [&]()
		{
			int i = std::rand() % 100 + -1000;
			GetWorld()->SpawnActor<AEnemy>(FVector(1000, FMath::RandRange(-1000, 1000), 0), FRotator(0, 0, 0));
		}, timer, true);
	GameBase->all_timer_handles.Add(TimerHandler);
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

