// Copyright Epic Games, Inc. All Rights Reserved.

#include "SiroTurrets2GameModeBase.h"
#include "PlayerCharacter.h"
#include "Blueprint/UserWidget.h"
#include "MenuHUD.h"
#include "GameHUDWidget.h"

ASiroTurrets2GameModeBase::ASiroTurrets2GameModeBase()
{
	//DefaultPawnClass = APlayerCharacter::StaticClass();

	//PlayerControllerClass = APlayerCharacter::StaticClass();
	//HUDClass = AMenuHUD::StaticClass();

	//menuHud = Cast<AMenuHUD>(CreateWidget(GetWorld(), MenuHUDClass));
	//check(menuHud);
	//WidgetClass = UGameHUDWidget::StaticClass();
	

}

void ASiroTurrets2GameModeBase::BeginPlay()
{
		GameHudWidget = Cast<UGameHUDWidget>(CreateWidget(GetWorld(), WidgetClass));
		GameHudWidget->InitializeHUD(this);
		GameHudWidget->AddToViewport();
}
