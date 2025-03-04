// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "I18NToolSettings.h"
#include "L10NEnums.h"
#include "LocalizationManager.h"
#include "Components/AudioComponent.h"
#include "Components/Widget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Sound/DialogueWave.h"
#include "L10NBlueprintLibrary.generated.h"


/**
 * 
 */
UCLASS()
class UL10NBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	// ---------------- Get L10N Properties ----------------

	// Get L10N Plain Text from DataTable
	UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Text", Category = "L10NTool", meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
	static FText GetL10NPlainText(const FName& InRowName, const UDataTable* InL10NData , const ELanguage InLanguage, UObject* WorldContextObject);

	// Get L10N Assets SoftObjectPath from DataTable
	UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Assets SoftObjectPath", Category = "L10NTool", meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
	static FSoftObjectPath GetL10NAssetsSoftObjectPath(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject);

	// Directly Get L10N Texture2D From DataTable
	UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Texture From Assets Data", Category = "L10NTool|DirectGet", meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
	static UTexture2D* GetL10NTextureFromAssetsData(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject);

	// Directly Get L10N Audio Cue From DataTable
	UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Audio From Assets Data", Category = "L10NTool|DirectGet", meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
	static USoundCue* GetL10NAudioFromAssetsData(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject);

	// Directly Get L10N Dialogue Wave From DataTable
	UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Dialogue From Assets Data", Category = "L10NTool|DirectGet", meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
	static UDialogueWave* GetL10NDialogueFromAssetsData(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject);
	
	// ---------------- Fast Set L10N Properties ----------------

	/**
	 * Directly sets the widget text With L10Ned Text from DataTable
	 * Warning: This will wipe any binding created for the Text property!
	 * 
	 * Will calling GetL10NPlainText and set the result to the TextBlock or RichTextBlock
	 * @param InWidget : Must be a TextBlock or RichTextBlock
	 * @param InRowName : Row Name
	 * @param InL10NData : Must be a valid L10N Plain Text DataTable
	 * @param InLanguage : The language to pick localization
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Set Text With L10N", Category = "L10NTool|FastSet", meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
	static void SetTextWithL10N(UObject* WorldContextObject, UWidget* InWidget, const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage);

	
	/**
	 * Plays a sound directly with no attenuation, perfect for UI sounds.
	 *
	 * * Fire and Forget.
	 * * Not Replicated.
	 *
	 * Will calling GetL10NAudioFromAssetsData and use UGameplayStatics::PlaySound2D to play the result
	 * @param InRowName - The name of the row in the L10N DataTable to play
	 * @param InL10NData - The L10N DataTable to play the sound from
	 * @param InLanguage - The language to pick localization
	 * @param VolumeMultiplier - A linear scalar multiplied with the volume, in order to make the sound louder or softer.
	 * @param PitchMultiplier - A linear scalar multiplied with the pitch.
	 * @param StartTime - How far in to the sound to begin playback at
 	 * @param ConcurrencySettings - Override concurrency settings package to play sound with
	 * @param OwningActor - The actor to use as the "owner" for concurrency settings purposes. 
	 *						Allows PlaySound calls to do a concurrency limit per owner.
	 * @param bIsUISound - True if sound is UI related, else false
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, DisplayName = "Play Sound2D With L10N", Category = "L10NTool|FastSet", meta=( WorldContext="WorldContextObject", AdvancedDisplay = "3", UnsafeDuringActorConstruction = "true", AutoCreateRefTerm = "InRowName" ))
	static void PlaySound2DWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f, float StartTime = 0.f, USoundConcurrency* ConcurrencySettings = nullptr, const AActor* OwningActor = nullptr, bool bIsUISound = true);

	/**
	 * Plays a sound at the given location. This is a fire and forget sound and does not travel with any actor. 
	 * Replication is also not handled at this point.
	 *
	 * Will calling GetL10NAudioFromAssetsData and use UGameplayStatics::PlaySoundAtLocation to play the result
	 * @param InRowName - The name of the row in the L10N DataTable to play
	 * @param InL10NData - The L10N DataTable to play the sound from
	 * @param InLanguage - The language to pick localization
	 * @param Location - World position to play sound at
	 * @param Rotation - World rotation to play sound at
	 * @param VolumeMultiplier - A linear scalar multiplied with the volume, in order to make the sound louder or softer.
	 * @param PitchMultiplier - A linear scalar multiplied with the pitch.
	 * @param StartTime - How far in to the sound to begin playback at
	 * @param AttenuationSettings - Override attenuation settings package to play sound with
	 * @param ConcurrencySettings - Override concurrency settings package to play sound with
	 * @param OwningActor - The actor to use as the "owner" for concurrency settings purposes. Allows PlaySound calls
	 *						to do a concurrency limit per owner.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Play Sound at Location With L10N", Category = "L10NTool|FastSet", meta=( WorldContext="WorldContextObject", AdvancedDisplay = "5", UnsafeDuringActorConstruction = "true", AutoCreateRefTerm = "InRowName", Keywords ="play" ))
	static void PlaySoundAtLocationWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject, FVector Location, FRotator Rotation, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f, float StartTime = 0.f, class USoundAttenuation* AttenuationSettings = nullptr, USoundConcurrency* ConcurrencySettings = nullptr, const AActor* OwningActor = nullptr, const UInitialActiveSoundParams* InitialParams = nullptr);

	/**
	 * Plays a dialogue directly with no attenuation, perfect for UI sounds.
	 *
	 * * Fire and Forget.
	 * * Not Replicated.
	 *
	 * Will calling GetL10NDialogueFromAssetsData and use UGameplayStatics::PlayDialogue2D to play the result
	 * @param InRowName - The name of the row in the L10N DataTable to play
	 * @param InL10NData - The L10N DataTable to play the sound from
	 * @param InLanguage - The language to pick localization
	 * @param Speaker - The voice that will be speaking the dialogue
	 * @param Targets - The voices that will be spoken to
	 * @param WorldContextObject - The world context
	 * @param VolumeMultiplier - A linear scalar multiplied with the volume, in order to make the sound louder or softer.
	 * @param PitchMultiplier - A linear scalar multiplied with the pitch.
	 * @param StartTime - How far in to the sound to begin playback at
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, DisplayName = "Play Dialogue2D With L10N", Category = "L10NTool|FastSet", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "5", UnsafeDuringActorConstruction = "true", AutoCreateRefTerm = "InRowName"))
	static void PlayDialogue2DWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UDialogueVoice* Speaker, TArray<UDialogueVoice*> Targets,  UObject* WorldContextObject, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f, float StartTime = 0.f);

	/**
	 * Plays a dialogue at the given location. This is a fire and forget sound and does not travel with any actor.
	 * Replication is also not handled at this point.
	 *
	 * Will calling GetL10NDialogueFromAssetsData and use UGameplayStatics::PlayDialogueAtLocation to play the result
	 * @param InRowName - The name of the row in the L10N DataTable to play
	 * @param InL10NData - The L10N DataTable to play the sound from
	 * @param InLanguage - The language to pick localization
	 * @param Speaker - The voice that will be speaking the dialogue
	 * @param Targets - The voices that will be spoken to
	 * @param WorldContextObject - The world context
	 * @param Location - World position to play sound at
	 * @param Rotation - World rotation to play sound at
	 * @param VolumeMultiplier - A linear scalar multiplied with the volume, in order to make the sound louder or softer.
	 * @param PitchMultiplier - A linear scalar multiplied with the pitch.
	 * @param StartTime - How far in to the sound to begin playback at
	 * @param AttenuationSettings - Override attenuation settings package to play sound with
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "Play Dialogue at Location With L10N", Category = "L10NTool|FastSet", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "6", UnsafeDuringActorConstruction = "true", AutoCreateRefTerm = "InRowName"))
	static void PlayDialogueAtLocationWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UDialogueVoice* Speaker, TArray<UDialogueVoice*> Targets, UObject* WorldContextObject, FVector Location, FRotator Rotation, float VolumeMultiplier = 1.f, float PitchMultiplier = 1.f, float StartTime = 0.f, USoundAttenuation* AttenuationSettings = nullptr);

	UFUNCTION(BlueprintCallable, DisplayName = "Set Image With L10N", Category = "L10NTool|FastSet", meta = (AutoCreateRefTerm = "InRowName", AdvancedDisplay = "4", WorldContext = "WorldContextObject"))
	static void SetImageWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject, UImage* InImage, const FSlateBrush& InBrushSetting = FSlateBrush());
	
	// ---------------- Get Global Properties ----------------

	// Get Supported Language, Return TArray<ELanguage>
	UFUNCTION(BlueprintPure, DisplayName = "Get L10N Supported Language", Category = "L10NTool|GetSettings" , meta = (WorldContext = "WorldContextObject"))
	static TArray<ELanguage> GetSupportedLanguage(UObject* WorldContextObject);

	// Get Supported Language Name And English Name, Return TArray<FString>, Example: "English", "简体中文 (Simplified Chinese)"
	UFUNCTION(BlueprintPure, DisplayName = "Get L10N Supported Language Name And English Name", Category = "L10NTool|GetSettings" , meta = (WorldContext = "WorldContextObject"))
	static TArray<FString> GetSupportedLanguageNames(UObject* WorldContextObject);

	// Get Supported Language Name And English Name Only, Return TArray<FString>, Example: "English", "简体中文"
	UFUNCTION(BlueprintPure, DisplayName = "Get L10N Supported Language Name", Category = "L10NTool|GetSettings", meta = (WorldContext = "WorldContextObject"))
	static TArray<FString> GetSupportedLanguagePureNames(UObject* WorldContextObject);
	
	// Get Current Global Language
	UFUNCTION(BlueprintPure, DisplayName = "Get Current Global Language", Category = "L10NTool|GetSettings", meta = (WorldContext = "WorldContextObject"))
	static ELanguage GetCurrentGlobalLanguage(UObject* WorldContextObject);

	// ---------------- Set Global Properties ----------------
	
	// Set Current Global Language
	UFUNCTION(BlueprintCallable, DisplayName = "Set Current Global Language", Category = "L10NTool|SetSettings" , meta = (WorldContext = "WorldContextObject"))
	static void SetCurrentGlobalLanguage(const ELanguage InLanguage, UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, DisplayName = "Get Localization Manager", meta = (WorldContext = "WorldContextObject"), Category = "L10NTool|GetSettings")
	static ALocalizationManager* GetLocalizationManager(const UObject* WorldContextObject);
	// ---------------- Private Method Signatures And Global Variables ----------------
private:
	UFUNCTION(meta = (WorldContext = "WorldContextObject"))
	static void CheckSupport(ELanguage InLanguage,UObject* WorldContextObject);
	static const TCHAR* ELanguageToString(const ELanguage InLanguage);
	UFUNCTION(meta = (WorldContext = "WorldContextObject"))
	static ELanguage GetDefaultLanguage(const UObject* WorldContextObject);
	static UI18NToolSettings* GetI18NToolSettings();
};
