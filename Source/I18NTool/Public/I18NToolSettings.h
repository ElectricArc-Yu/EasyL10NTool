// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025

#pragma once

#include "CoreMinimal.h"
#include "L10NEnums.h"
#include "UObject/Object.h"
#include "I18NToolSettings.generated.h"


/**
 * 
 */
UCLASS(config=Game, defaultconfig)
class I18NTOOL_API UI18NToolSettings : public UObject 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="L10N")
	TArray<ELanguage> SupportedLanguage = {ELanguage::English};

	UPROPERTY(EditAnywhere, Config, Category="L10N")
	bool bIUnderStandIsNotSuggestedToChangeDefaultLanguage = false;

	// Which means the original language of the game none of the translation is applied
	UPROPERTY(EditAnywhere, Config, Category="L10N",
		meta=(EditCondition="bIUnderStandIsNotSuggestedToChangeDefaultLanguage"))
	ELanguage DefaultLanguage = ELanguage::English;

	UPROPERTY(EditAnywhere, Category="L10N")
	ELanguage DebugLanguage = ELanguage::English;

	UPROPERTY(Config)
	ELanguage CurrentGlobalLanguage = DefaultLanguage;

	// Getters
	TArray<ELanguage> GetSupportedLanguage() const { return SupportedLanguage; }
	ELanguage GetCurrentGlobalLanguage() const { return CurrentGlobalLanguage; }
	ELanguage GetDefaultLanguage() const { return DefaultLanguage; }

	// Setters
	void SetCurrentGlobalLanguage(const ELanguage InLanguage);

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);
};
