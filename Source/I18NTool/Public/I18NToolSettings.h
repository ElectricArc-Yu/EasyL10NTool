// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "L10NEnums.h"
#include "UObject/Object.h"
#include "I18NToolSettings.generated.h"

/**
 * 
 */
UCLASS(config=game, DefaultConfig, meta=(DisplayName="Easy L10N & I18N Tool"))
class I18NTOOL_API UI18NToolSettings : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Config, Category="L10N")
	TArray<ELanguage> SupportedLanguage = {ELanguage::English};
	UPROPERTY(EditAnywhere, Config, Category="L10N")
	ELanguage CurrentGlobalLanguage;

	// Getters
	TArray<ELanguage> GetSupportedLanguage() const { return SupportedLanguage; }
	ELanguage GetCurrentGlobalLanguage() const { return CurrentGlobalLanguage; }

	// Setters
	void SetCurrentGlobalLanguage(const ELanguage InLanguage) { CurrentGlobalLanguage = InLanguage; }
	
};
