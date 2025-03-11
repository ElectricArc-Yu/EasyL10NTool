// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025


#include "LocalizationManager.h"

#include "I18NToolSettings.h"

// Sets default values
ALocalizationManager::ALocalizationManager()
{
	// Disable tick
	PrimaryActorTick.bCanEverTick = false;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SupportedLanguage = {ELanguage::English};
	DefaultLanguage = ELanguage::English;
	CurrentGlobalLanguage = ELanguage::English;
#if WITH_EDITOR
	DebugLanguage = ELanguage::English;
#endif
}

// Called when the game starts or when spawned
void ALocalizationManager::BeginPlay()
{
	Super::BeginPlay();
	if (UI18NToolSettings* Settings = GetMutableDefault<UI18NToolSettings>())
	{
		SupportedLanguage = Settings->GetSupportedLanguage();
#if WITH_EDITOR
		DebugLanguage = Settings->DebugLanguage;
		CurrentGlobalLanguage = DebugLanguage;
#else
		CurrentGlobalLanguage = Settings->GetCurrentGlobalLanguage();
#endif
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[LocalizationManager] Cannot find I18NToolSettings"));
	}
}

// Called every frame
void ALocalizationManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALocalizationManager::RuntimeSetCurrentGlobalLanguage(const ELanguage InLanguage)
{
	CurrentGlobalLanguage = InLanguage;
	OnCurrentGlobalLanguageChanged.Broadcast();
}
