// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SiroTurrets2GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class SIROTURRETS2_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* HighScore;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Lives;

	UFUNCTION(BlueprintCallable)
	void InitializeHUD(ASiroTurrets2GameModeBase* RunGameMode);

	UFUNCTION(BlueprintCallable)
	void SetScore(int32 score);
	
};
