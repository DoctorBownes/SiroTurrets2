// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "Components/TextBlock.h"

void UGameHUDWidget::InitializeHUD(ASiroTurrets2GameModeBase* RunGameMode)
{
	if (RunGameMode)
	{
		HighScore->SetText(FText::FromString("HighScore: 0"));

		RunGameMode->OnEnemyHit.AddDynamic(this, &UGameHUDWidget::SetScore);
	}
}

void UGameHUDWidget::SetScore(const int32 score)
{
	HighScore->SetText(FText::AsNumber(score));
}
