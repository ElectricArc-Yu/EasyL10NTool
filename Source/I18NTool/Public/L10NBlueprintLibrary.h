// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "L10NEnums.h"
#include "L10NStructs.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "L10NBlueprintLibrary.generated.h"



/**
 * 
 */
UCLASS()
class UL10NBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// ---------------- Get L10N Properties ----------------
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get L10N Text", Keywords = "Will return FText with InLanguage and InRowName by InL10NData"), Category = "L10NTool")
	static FText GetL10NPlainText(const FName& InRowName, const UDataTable* InL10NData , const ELanguage InLanguage);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get L10N Art SoftObjectPath", Keywords = "Will return FSoftObjectPath with InLanguage and InRowName by InL10NData\nNULLABLE RETURN"), Category = "L10NTool")
	static FSoftObjectPath GetL10NArtSoftObjectPath(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get L10N Art Texture", Keywords = "Will return UTexture2D with InLanguage and InRowName by InL10NData\nNULLABLE RETURN"), Category = "L10NTool")
	static UTexture2D* GetL10NArtTexture(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage);
	
	// ---------------- Get Global Properties ----------------
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get L10N Text With Row", Keywords = "Get Supported Language"), Category = "L10NTool")
	static TArray<ELanguage> GetSupportedLanguage();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Current Global Language", Keywords = "Get Global Language"), Category = "L10NTool")
	static ELanguage GetCurrentGlobalLanguage();

	// ---------------- Set Global Properties ----------------
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Current Global Language", Keywords = "Set Global Language"), Category = "L10NTool")
	static void SetCurrentGlobalLanguage(const ELanguage InLanguage);

	// ---------------- Private Method Signatures ----------------
	static void CheckSupport(ELanguage InLanguage);
};
