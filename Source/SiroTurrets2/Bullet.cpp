// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("My Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	//StaticMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	SphereCollision = CreateDefaultSubobject<USphereComponent>("Collision Sphere");
	StaticMesh->SetStaticMesh(mesh.Object);
	SetRootComponent(StaticMesh);

	ProjectTile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectTile->SetUpdatedComponent(SphereCollision);
	ProjectTile->InitialSpeed = 3000.0f;
	ProjectTile->MaxSpeed = 3000.0f;
	ProjectTile->bRotationFollowsVelocity = true;
	ProjectTile->Bounciness = 0.3f;
	ProjectTile->ProjectileGravityScale = 0.0f;
}

void ABullet::FireInDirection(const FVector& ShootDirection)
{
	ProjectTile->Velocity = ShootDirection * ProjectTile->InitialSpeed;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();


	SphereCollision->SetRelativeLocation(FVector(0, 0, 0));
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnCollisionHit);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnCollisionHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (OtherActor->ActorHasTag("Enemy"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit"));
	}
}
