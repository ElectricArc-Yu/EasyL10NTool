# UL10NBlueprintLibrary Documentation

## Overview
`UL10NBlueprintLibrary` is a Blueprint Function Library in Unreal Engine that provides a set of functions for handling localization (L10N) tasks. It allows developers to retrieve localized text, assets, and play localized audio and dialogue, as well as manage global localization settings.

## Class Definition
```cpp
UCLASS()
class UL10NBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()
    // ... Function declarations ...
};
```

## Function Categories

### 1. Get L10N Properties
These functions are used to retrieve localized text, assets, and specific asset types from a DataTable.

#### GetL10NPlainText
- **Description**: Retrieves localized plain text from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Text", Category = "L10NTool",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static FText GetL10NPlainText(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage,
                              UObject* WorldContextObject);
```
- **Parameters**:
    - `InRowName`: The name of the row in the DataTable.
    - `InL10NData`: The DataTable containing the localization data.
    - `InLanguage`: The language for which to retrieve the localization.
    - `WorldContextObject`: The world context object.
- **Returns**: The localized plain text.

#### GetL10NAssetsSoftObjectPath
- **Description**: Retrieves the soft object path of a localized asset from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Assets SoftObjectPath", Category = "L10NTool",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static FSoftObjectPath GetL10NAssetsSoftObjectPath(const FName& InRowName, const UDataTable* InL10NData,
                                                   const ELanguage InLanguage, UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetL10NPlainText`.
- **Returns**: The soft object path of the localized asset.

#### GetL10NAssetsObject
- **Description**: Retrieves the object of a localized asset from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Assets Object", Category = "L10NTool",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static UObject* GetL10NAssetsObject(const FName& InRowName, const UDataTable* InL10NData,
                                    const ELanguage InLanguage, UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetL10NPlainText`.
- **Returns**: The object of the localized asset.

#### GetL10NTextureFromAssetsData
- **Description**: Directly retrieves a localized `UTexture2D` from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Texture From Assets Data", Category = "L10NTool|DirectGet",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static UTexture2D* GetL10NTextureFromAssetsData(const FName& InRowName, const UDataTable* InL10NData,
                                                const ELanguage InLanguage, UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetL10NPlainText`.
- **Returns**: The localized `UTexture2D` object.

#### GetL10NAudioFromAssetsData
- **Description**: Directly retrieves a localized `USoundCue` from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Audio From Assets Data", Category = "L10NTool|DirectGet",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static USoundCue* GetL10NAudioFromAssetsData(const FName& InRowName, const UDataTable* InL10NData,
                                             const ELanguage InLanguage, UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetL10NPlainText`.
- **Returns**: The localized `USoundCue` object.

#### GetL10NDialogueFromAssetsData
- **Description**: Directly retrieves a localized `UDialogueWave` from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Get L10N Dialogue From Assets Data", Category = "L10NTool|DirectGet",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static UDialogueWave* GetL10NDialogueFromAssetsData(const FName& InRowName, const UDataTable* InL10NData,
                                                    const ELanguage InLanguage, UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetL10NPlainText`.
- **Returns**: The localized `UDialogueWave` object.

### 2. Fast Set L10N Properties
These functions are used to quickly set localized properties on widgets and play localized audio and dialogue.

#### SetTextWithL10N
- **Description**: Directly sets the text of a widget (TextBlock or RichTextBlock) with localized text from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Set Text With L10N", Category = "L10NTool|FastSet",
    meta = (AutoCreateRefTerm = "InRowName", WorldContext="WorldContextObject"))
static void SetTextWithL10N(UObject* WorldContextObject, UWidget* InWidget, const FName& InRowName,
                            const UDataTable* InL10NData, const ELanguage InLanguage);
```
- **Parameters**:
    - `WorldContextObject`: The world context object.
    - `InWidget`: The widget (must be a TextBlock or RichTextBlock).
    - `InRowName`: The name of the row in the DataTable.
    - `InL10NData`: The DataTable containing the localization data.
    - `InLanguage`: The language for which to retrieve the localization.

#### PlaySound2DWithL10N
- **Description**: Plays a localized 2D sound with no attenuation, suitable for UI sounds.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, BlueprintCosmetic, DisplayName = "Play Sound2D With L10N",
    Category = "L10NTool|FastSet",
    meta=( WorldContext="WorldContextObject", AdvancedDisplay = "3", UnsafeDuringActorConstruction = "true",
        AutoCreateRefTerm = "InRowName" ))
static void PlaySound2DWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage,
                                UObject* WorldContextObject, float VolumeMultiplier = 1.f,
                                float PitchMultiplier = 1.f, float StartTime = 0.f,
                                USoundConcurrency* ConcurrencySettings = nullptr,
                                const AActor* OwningActor = nullptr, bool bIsUISound = true);
```
- **Parameters**:
    - `InRowName`: The name of the row in the DataTable.
    - `InL10NData`: The DataTable containing the localization data.
    - `InLanguage`: The language for which to retrieve the localization.
    - `WorldContextObject`: The world context object.
    - `VolumeMultiplier`: A linear scalar multiplied with the volume.
    - `PitchMultiplier`: A linear scalar multiplied with the pitch.
    - `StartTime`: How far in to the sound to begin playback at.
    - `ConcurrencySettings`: Override concurrency settings package to play sound with.
    - `OwningActor`: The actor to use as the "owner" for concurrency settings purposes.
    - `bIsUISound`: True if the sound is UI related, else false.

#### PlaySoundAtLocationWithL10N
- **Description**: Plays a localized sound at a given location.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Play Sound at Location With L10N", Category = "L10NTool|FastSet",
    meta=( WorldContext="WorldContextObject", AdvancedDisplay = "5", UnsafeDuringActorConstruction = "true",
        AutoCreateRefTerm = "InRowName", Keywords ="play" ))
static void PlaySoundAtLocationWithL10N(const FName& InRowName, const UDataTable* InL10NData,
                                        const ELanguage InLanguage, UObject* WorldContextObject, FVector Location,
                                        FRotator Rotation, float VolumeMultiplier = 1.f,
                                        float PitchMultiplier = 1.f, float StartTime = 0.f,
                                        class USoundAttenuation* AttenuationSettings = nullptr,
                                        USoundConcurrency* ConcurrencySettings = nullptr,
                                        const AActor* OwningActor = nullptr,
                                        const UInitialActiveSoundParams* InitialParams = nullptr);
```
- **Parameters**: Similar to `PlaySound2DWithL10N`, with additional `Location` and `Rotation` parameters.

#### PlayDialogue2DWithL10N
- **Description**: Plays a localized 2D dialogue with no attenuation.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, BlueprintCosmetic, DisplayName = "Play Dialogue2D With L10N",
    Category = "L10NTool|FastSet",
    meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "5", UnsafeDuringActorConstruction = "true",
        AutoCreateRefTerm = "InRowName"))
static void PlayDialogue2DWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage,
                                   UDialogueVoice* Speaker, TArray<UDialogueVoice*> Targets,
                                   UObject* WorldContextObject, float VolumeMultiplier = 1.f,
                                   float PitchMultiplier = 1.f, float StartTime = 0.f);
```
- **Parameters**:
    - Similar to `PlaySound2DWithL10N`, with additional `Speaker` and `Targets` parameters.

#### PlayDialogueAtLocationWithL10N
- **Description**: Plays a localized dialogue at a given location.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Play Dialogue at Location With L10N", Category = "L10NTool|FastSet",
    meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "6", UnsafeDuringActorConstruction = "true",
        AutoCreateRefTerm = "InRowName"))
static void PlayDialogueAtLocationWithL10N(const FName& InRowName, const UDataTable* InL10NData,
                                           const ELanguage InLanguage, UDialogueVoice* Speaker,
                                           TArray<UDialogueVoice*> Targets, UObject* WorldContextObject,
                                           FVector Location, FRotator Rotation, float VolumeMultiplier = 1.f,
                                           float PitchMultiplier = 1.f, float StartTime = 0.f,
                                           USoundAttenuation* AttenuationSettings = nullptr);
```
- **Parameters**: Similar to `PlayDialogue2DWithL10N`, with additional `Location` and `Rotation` parameters.

#### SetImageWithL10N
- **Description**: Sets the image of a `UImage` widget with a localized texture from a DataTable.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Set Image With L10N", Category = "L10NTool|FastSet",
    meta = (AutoCreateRefTerm = "InRowName", AdvancedDisplay = "4", WorldContext = "WorldContextObject"))
static void SetImageWithL10N(const FName& InRowName, const UDataTable* InL10NData, const ELanguage InLanguage,
                             UObject* WorldContextObject, UImage* InImage,
                             const FSlateBrush& InBrushSetting = FSlateBrush());
```
- **Parameters**:
    - `InRowName`: The name of the row in the DataTable.
    - `InL10NData`: The DataTable containing the localization data.
    - `InLanguage`: The language for which to retrieve the localization.
    - `WorldContextObject`: The world context object.
    - `InImage`: The `UImage` widget to set the image on.
    - `InBrushSetting`: The brush setting for the image.

### 3. Get Global Properties
These functions are used to retrieve information about supported languages and the current global language.

#### GetSupportedLanguage
- **Description**: Retrieves an array of supported languages.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintPure, DisplayName = "Get L10N Supported Language", Category = "L10NTool|GetSettings",
    meta = (WorldContext = "WorldContextObject"))
static TArray<ELanguage> GetSupportedLanguage(UObject* WorldContextObject);
```
- **Parameters**:
    - `WorldContextObject`: The world context object.
- **Returns**: An array of `ELanguage` values representing the supported languages.

#### GetSupportedLanguageNames
- **Description**: Retrieves an array of supported language names and their English names.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintPure, DisplayName = "Get L10N Supported Language Name And English Name",
    Category = "L10NTool|GetSettings", meta = (WorldContext = "WorldContextObject"))
static TArray<FString> GetSupportedLanguageNames(UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetSupportedLanguage`.
- **Returns**: An array of `FString` values representing the language names and their English names.

#### GetSupportedLanguagePureNames
- **Description**: Retrieves an array of supported language names only.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintPure, DisplayName = "Get L10N Supported Language Name", Category = "L10NTool|GetSettings",
    meta = (WorldContext = "WorldContextObject"))
static TArray<FString> GetSupportedLanguagePureNames(UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetSupportedLanguage`.
- **Returns**: An array of `FString` values representing the language names.

#### GetCurrentGlobalLanguage
- **Description**: Retrieves the current global language.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintPure, DisplayName = "Get Current Global Language", Category = "L10NTool|GetSettings",
    meta = (WorldContext = "WorldContextObject"))
static ELanguage GetCurrentGlobalLanguage(UObject* WorldContextObject);
```
- **Parameters**: Similar to `GetSupportedLanguage`.
- **Returns**: The current global language as an `ELanguage` value.

### 4. Set Global Properties
These functions are used to set the current global language.

#### SetCurrentGlobalLanguage
- **Description**: Sets the current global language.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintCallable, DisplayName = "Set Current Global Language", Category = "L10NTool|SetSettings",
    meta = (WorldContext = "WorldContextObject"))
static void SetCurrentGlobalLanguage(const ELanguage InLanguage, UObject* WorldContextObject);
```
- **Parameters**:
    - `InLanguage`: The language to set as the current global language.
    - `WorldContextObject`: The world context object.

### 5. Other Functions
#### GetLocalizationManager
- **Description**: Retrieves the `ALocalizationManager` object.
- **Function Signature**:
```cpp
UFUNCTION(BlueprintPure, DisplayName = "Get Localization Manager", meta = (WorldContext = "WorldContextObject"),
    Category = "L10NTool|GetSettings")
static ALocalizationManager* GetLocalizationManager(const UObject* WorldContextObject);
```
- **Parameters**:
    - `WorldContextObject`: The world context object.
- **Returns**: The `ALocalizationManager` object.

### Private Methods
- `CheckSupport`: Checks if a given language is supported.
- `ELanguageToString`: Converts an `ELanguage` value to a string.
- `GetDefaultLanguage`: Retrieves the default language.
- `GetI18NToolSettings`: Retrieves the `UI18NToolSettings` object.

These private methods are not directly accessible from Blueprint but are used internally by the public functions.