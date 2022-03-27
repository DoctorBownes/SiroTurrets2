// Copyright Epic Games, Inc. All Rights Reserved.

#include "SiroTurrets2GameModeBase.h"
#include "PlayerCharacter.h"
#include "MenuHUD.h"

ASiroTurrets2GameModeBase::ASiroTurrets2GameModeBase()
{
	//DefaultPawnClass = APlayerCharacter::StaticClass();

	//PlayerControllerClass = APlayerCharacter::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
