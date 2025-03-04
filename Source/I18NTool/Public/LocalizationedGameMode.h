// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LocalizationManager.h"
#include "GameFramework/GameModeBase.h"
#include "LocalizationedGameMode.generated.h"

/**
 * 
 */
UCLASS()
class I18NTOOL_API ALocalizationedGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Classes, meta = (DisplayName = "Localization Manager Class"))
	TSubclassOf<ALocalizationManager> LocalizationManagerClass = ALocalizationManager::StaticClass();

	virtual void BeginPlay() override;
	ALocalizationManager* GetLocalizationManagerInstance() const {return LocalizationManagerInstance;}
private:
	UPROPERTY()
	ALocalizationManager* LocalizationManagerInstance;
};
