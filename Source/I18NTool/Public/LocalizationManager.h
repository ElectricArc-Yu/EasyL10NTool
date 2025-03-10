// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "L10NEnums.h"
#include "GameFramework/Actor.h"
#include "LocalizationManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCurrentGlobalLanguageChanged);

UCLASS()
class I18NTOOL_API ALocalizationManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALocalizationManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Variables
	TArray<ELanguage> SupportedLanguage;
	ELanguage DefaultLanguage;
#if WITH_EDITOR
	ELanguage DebugLanguage;
#endif
	ELanguage CurrentGlobalLanguage;
	UPROPERTY(BlueprintAssignable, Category="L10N")
	FOnCurrentGlobalLanguageChanged OnCurrentGlobalLanguageChanged;

	// Setters
	void RuntimeSetCurrentGlobalLanguage(const ELanguage InLanguage);
};
