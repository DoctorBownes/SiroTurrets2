// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "MenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	//if (GEngine && GEngine->GameViewport)
	//{
	//	menuWidget = SNew(MenuWidget).OwningHUD(this);
	//	GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(menuWidgetContainer, SWeakWidget).PossiblyNullContent(menuWidget.ToSharedRef()));
	//}
}

void AMenuHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMenuHUD::InitializeHUD(ASiroTurrets2GameModeBase* RunGameMode)
{
	if (RunGameMode)
	{
	}
}

void AMenuHUD::SetScore(int32 score)
{

}
