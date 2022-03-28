// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SiroTurrets2GameModeBase.generated.h"

class UUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyHit, int32, HighScore);

/**
 * 
 */
UCLASS()
class SIROTURRETS2_API ASiroTurrets2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASiroTurrets2GameModeBase();


	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UGameHUDWidget* GameHudWidget;


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnEnemyHit OnEnemyHit;

	virtual void BeginPlay() override;
	
};
