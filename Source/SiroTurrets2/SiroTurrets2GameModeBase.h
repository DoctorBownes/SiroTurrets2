// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SiroTurrets2GameModeBase.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class SIROTURRETS2_API ASiroTurrets2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASiroTurrets2GameModeBase();

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> MenuHUDClass;
	
};
