// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UPROPERTY(meta = (BindWidget))
	UTextBlock* HighScore;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Lives;

	
};
