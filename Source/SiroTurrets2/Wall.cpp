// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameHUDWidget.h"
#include "SiroTurrets2GameModeBase.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Wall Collision");
	BoxComponent->SetWorldLocation(FVector(-1200, 0, 0));
	BoxComponent->SetWorldScale3D(FVector(1, 55, 1));

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWall::OnCollisionHit);
	GameBase = Cast<ASiroTurrets2GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	PlayerController->InputComponent->BindAction("SpacePress", IE_Pressed, this, &AWall::SpacePressed).bExecuteWhenPaused = true;
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWall::SpacePressed()
{
	if (health < 0)
	{
		GameBase->GameOver(true);
	}
}

void AWall::OnCollisionHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (OtherActor->ActorHasTag("Enemy"))
	{
		OtherActor->Destroy();
		health--;
		GameBase->GameHudWidget->SetLives(health);
		UE_LOG(LogTemp, Warning, TEXT("%d"), health);
		if (health < 0)
		{
			GameBase->GameOver();
		}
	}
}
