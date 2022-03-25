// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("My Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	//mesh.Object.
	SetRootComponent(StaticMesh);
	//UStaticMesh* Cube = CreateDefaultSubobject<UStaticMesh>("Shape_Cube");
	StaticMesh->SetStaticMesh(mesh.Object);
	StaticMesh->SetWorldScale3D(FVector(2, 1, 1));
}

void ATurret::Fire()
{
	ABullet* bullet = GetWorld()->SpawnActor<ABullet>((GetActorLocation() + GetActorForwardVector() * 200), FRotator(0, 0, 0));
	bullet->FireInDirection(GetActorForwardVector());
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	this->Tags.Add("Turret");
	//BoxCollision->OnComponentHit.AddDynamic(this, &OnCollisionHit);
	//FTimerHandle TimerHandle;
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
	//	{
	//		//Fire();
	//	}, 2, true);
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret::OnCollisionHit(UPrimitiveComponent* OnComponentHit, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
}
