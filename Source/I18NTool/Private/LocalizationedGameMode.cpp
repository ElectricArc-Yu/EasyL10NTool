// Fill out your copyright notice in the Description page of Project Settings.
#include "LocalizationedGameMode.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"


void ALocalizationedGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (UWorld* World = GetWorld())
	{
		if (!LocalizationManagerInstance)
		{
			FActorSpawnParameters Params;
			Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			LocalizationManagerInstance = World->SpawnActor<ALocalizationManager>(LocalizationManagerClass, Params);
		}
	}
}
