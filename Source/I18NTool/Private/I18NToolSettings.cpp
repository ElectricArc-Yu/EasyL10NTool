// Fill out your copyright notice in the Description page of Project Settings.


#include "I18NToolSettings.h"

#include "Blueprint/UserWidget.h"
#include "Internationalization/Culture.h"
#include "Kismet/GameplayStatics.h"

void UI18NToolSettings::SetCurrentGlobalLanguage(const ELanguage InLanguage)
{
	CurrentGlobalLanguage = InLanguage;
}


void UI18NToolSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UObject::PostEditChangeProperty(PropertyChangedEvent);
	FString Name = PropertyChangedEvent.Property->GetName();
	
}

