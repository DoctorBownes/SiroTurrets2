// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include <string>
#include <sstream>

void UGameHUDWidget::InitializeHUD(ASiroTurrets2GameModeBase* RunGameMode)
{
	if (RunGameMode)
	{
		SetLives(3);
		SetScore(0);
		GameOverScreen->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UGameHUDWidget::SetScore(const int32 score)
{
	std::stringstream sstream;
	sstream << "Highscore: " << score;
	HighScore->SetText(FText::FromString(sstream.str().c_str()));
}

void UGameHUDWidget::SetLives(int32 amountlives)
{
	std::stringstream sstream;
	sstream << "Lives: " << amountlives;
	Lives->SetText(FText::FromString(sstream.str().c_str()));
}
