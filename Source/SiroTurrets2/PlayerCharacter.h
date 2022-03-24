// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turret.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SIROTURRETS2_API APlayerCharacter : public ATurret
{
	GENERATED_BODY()

	//UPROPERTY(VisibleAnywhere)
	//class USpringArmComponent* CameraBoom;

	//UPROPERTY(VisibleAnywhere)
	//class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};