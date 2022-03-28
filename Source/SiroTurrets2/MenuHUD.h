// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SiroTurrets2GameModeBase.h"
#include "GameHUDWidget.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class SIROTURRETS2_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	TSharedPtr<class MenuWidget> menuWidget;
	TSharedPtr<class SWidget> menuWidgetContainer;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:
	void InitializeHUD(ASiroTurrets2GameModeBase* RunGameMode);

	void SetScore(int32 score);

};
