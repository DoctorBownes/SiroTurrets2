// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "PlayerCharacter.h"
#include <string>

void MenuWidget::Construct(const FArguments& InArgs)
{
	const FMargin ContentPadding = FMargin(500.0f, 300.0f);

	

	const FText TitleText = FText::FromString("HighScore: ");

	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 40.0f;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		//[
		//	SNew(SImage)
		//	.ColorAndOpacity(FColor::Black)
		//]
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		[
			SNew(STextBlock).Tag("HighScore")
			.Font(TextStyle)
		.Text(TitleText)
		.Justification(ETextJustify::Center)
			]
		]
		];
}
