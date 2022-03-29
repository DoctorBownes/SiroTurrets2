// Copyright Epic Games, Inc. All Rights Reserved.

#include "SiroTurrets2GameModeBase.h"
#include "PlayerCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
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
		score = 0;
}

void ASiroTurrets2GameModeBase::AddScore()
{
	score += 10;
	//GameHudWidget->SetLives(32);
	GameHudWidget->SetScore(score);
}

void ASiroTurrets2GameModeBase::GameOver(bool shouldReset)
{
	if (shouldReset)
	{
		UGameplayStatics::SetGamePaused(this, false);
		GameHudWidget->GameOverScreen->SetVisibility(ESlateVisibility::Hidden);
		for (int i = 0; i < all_timer_handles.Num(); i++)
		{
			GetGameInstance()->GetTimerManager().ClearTimer(all_timer_handles[i]);
		}
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	else
	{
		UGameplayStatics::SetGamePaused(this, true);
		GameHudWidget->GameOverScreen->SetVisibility(ESlateVisibility::Visible);
	}
}
