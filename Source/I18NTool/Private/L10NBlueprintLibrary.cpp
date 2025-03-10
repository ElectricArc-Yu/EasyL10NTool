// Fill out your copyright notice in the Description page of Project Settings.

#include "L10NBlueprintLibrary.h"

#include "EngineUtils.h"
#include "L10NEnums.h"
#include "I18NToolSettings.h"
#include "L10NStructs.h"
#include "LocalizationedGameMode.h"
#include "Components/Image.h"
#include "Components/RichTextBlock.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "UObject/TemplateString.h"

class URichTextBlock;
class UTextBlock;

UL10NBlueprintLibrary::UL10NBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

/**
 * Get L10N Plain Text from DataTable
 * @brief If the language row is empty, it will return the default language row automatically.
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Plain Text DataTable
 * @param InLanguage : Language
 * @param WorldContextObject : World Context Object
 * @return FText : L10N Plain Text or "Bad DataTable" in InL10NData is not a valid L10N Plain Text DataTable or "Cannot Find Row" in InRowName is not found in InL10NData Row Name.
 */
FText UL10NBlueprintLibrary::GetL10NPlainText(const FName& InRowName, const UDataTable* InL10NData,
                                         const ELanguage InLanguage, UObject* WorldContextObject)
{
	if (!GetSupportedLanguage(WorldContextObject).Contains(InLanguage))
	{
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool] Try to get a unsupported language : %s"), ELanguageToString(InLanguage));
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool Hint] If you want support a language add SupportedLanguage in Project Settings -> Easy I18NTool -> Easy L10N Tool -> Supported Language"));
	}
	if (InL10NData->GetRowStruct() != FL10NPlainTextTable::StaticStruct())
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The DataTable %s is not a valid L10N Plain Text DataTable"), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		return FText::FromString(FString::Printf(TEXT("Bad Datatable")));
	}
	FL10NPlainTextTable* Row = InL10NData->FindRow<FL10NPlainTextTable>(InRowName, TEXT("Row Name"), true);
	if (!Row)
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s is not found in DataTable %s"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		return FText::FromString(FString::Printf(TEXT("Cannot Find Row")));
	}
	FText Result;
#pragma region Switch and return
	switch (InLanguage) {
	case ELanguage::English:
		Result=Row->English;
		break;
	case ELanguage::SimplifiedChinese:
		Result=Row->SimplifiedChinese;
		break;
	case ELanguage::TraditionalChinese:
		Result=Row->TraditionalChinese;
		break;
	case ELanguage::Japanese:
		Result=Row->Japanese;
		break;
	case ELanguage::Korean:
		Result=Row->Korean;
		break;
	case ELanguage::French:
		Result=Row->French;
		break;
	case ELanguage::German:
		Result=Row->German;
		break;
	case ELanguage::SpanishSpain:
		Result=Row->SpanishSpain;
		break;
	case ELanguage::SpanishLatinAmerica:
		Result=Row->SpanishLatinAmerica;
		break;
	case ELanguage::Italian:
		Result=Row->Italian;
		break;
	case ELanguage::Thai:
		Result=Row->Thai;
		break;
	case ELanguage::Bulgarian:
		Result=Row->Bulgarian;
		break;
	case ELanguage::Czech:
		Result=Row->Czech;
		break;
	case ELanguage::Danish:
		Result=Row->Danish;
		break;
	case ELanguage::Greek:
		Result=Row->Greek;
		break;
	case ELanguage::BahasaIndonesia:
		Result=Row->BahasaIndonesia;
		break;
	case ELanguage::Hungarian:
		Result=Row->Hungarian;
		break;
	case ELanguage::Dutch:
		Result=Row->Dutch;
		break;
	case ELanguage::Norwegian:
		Result=Row->Norwegian;
		break;
	case ELanguage::Polish:
		Result=Row->Polish;
		break;
	case ELanguage::PortugueseBrazil:
		Result=Row->PortugueseBrazil;
		break;
	case ELanguage::PortuguesePortugal:
		Result=Row->PortuguesePortugal;
		break;
	case ELanguage::Romanian:
		Result=Row->Romanian;
		break;
	case ELanguage::Russian:
		Result=Row->Russian;
		break;
	case ELanguage::Finnish:
		Result=Row->Finnish;
		break;
	case ELanguage::Swedish:
		Result=Row->Swedish;
		break;
	case ELanguage::Turkish:
		Result=Row->Turkish;
		break;
	case ELanguage::Vietnamese:
		Result=Row->Vietnamese;
		break;
	case ELanguage::Ukrainian:
		Result=Row->Ukrainian;
		break;
	}
#pragma endregion
	if (Result.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not support language %s"), *InRowName.ToString(), *InL10NData->GetName(), ELanguageToString(InLanguage));
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] Try to rise the default language result"));
#pragma region Switch and return
		switch (GetDefaultLanguage(WorldContextObject)) {
		case ELanguage::English:
			Result=Row->English;
			break;
		case ELanguage::SimplifiedChinese:
			Result=Row->SimplifiedChinese;
			break;
		case ELanguage::TraditionalChinese:
			Result=Row->TraditionalChinese;
			break;
		case ELanguage::Japanese:
			Result=Row->Japanese;
			break;
		case ELanguage::Korean:
			Result=Row->Korean;
			break;
		case ELanguage::French:
			Result=Row->French;
			break;
		case ELanguage::German:
			Result=Row->German;
			break;
		case ELanguage::SpanishSpain:
			Result=Row->SpanishSpain;
			break;
		case ELanguage::SpanishLatinAmerica:
			Result=Row->SpanishLatinAmerica;
			break;
		case ELanguage::Italian:
			Result=Row->Italian;
			break;
		case ELanguage::Thai:
			Result=Row->Thai;
			break;
		case ELanguage::Bulgarian:
			Result=Row->Bulgarian;
			break;
		case ELanguage::Czech:
			Result=Row->Czech;
			break;
		case ELanguage::Danish:
			Result=Row->Danish;
			break;
		case ELanguage::Greek:
			Result=Row->Greek;
			break;
		case ELanguage::BahasaIndonesia:
			Result=Row->BahasaIndonesia;
			break;
		case ELanguage::Hungarian:
			Result=Row->Hungarian;
			break;
		case ELanguage::Dutch:
			Result=Row->Dutch;
			break;
		case ELanguage::Norwegian:
			Result=Row->Norwegian;
			break;
		case ELanguage::Polish:
			Result=Row->Polish;
			break;
		case ELanguage::PortugueseBrazil:
			Result=Row->PortugueseBrazil;
			break;
		case ELanguage::PortuguesePortugal:
			Result=Row->PortuguesePortugal;
			break;
		case ELanguage::Romanian:
			Result=Row->Romanian;
			break;
		case ELanguage::Russian:
			Result=Row->Russian;
			break;
		case ELanguage::Finnish:
			Result=Row->Finnish;
			break;
		case ELanguage::Swedish:
			Result=Row->Swedish;
			break;
		case ELanguage::Turkish:
			Result=Row->Turkish;
			break;
		case ELanguage::Vietnamese:
			Result=Row->Vietnamese;
			break;
		case ELanguage::Ukrainian:
			Result=Row->Ukrainian;
			break;
		}
#pragma endregion
	}
	return Result;
}



/**
 * Get L10N Art SoftObjectPath from DataTable
 * @brief If the language row is empty, it will return the default language row automatically.
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Art DataTable
 * @param InLanguage : Language
 * @param WorldContextObject : The world context
 * @return FSoftObjectPath : L10N Assets SoftObjectPath or nullptr in InL10NData is not a valid L10N Assets DataTable or "Cannot Find Row" in InRowName is not found in InL10NData Row Name.
 */
FSoftObjectPath UL10NBlueprintLibrary::GetL10NAssetsSoftObjectPath(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UObject* WorldContextObject)
{
	CheckSupport(InLanguage,WorldContextObject);
	if (InL10NData->GetRowStruct() != FL10NAssetsTable::StaticStruct())
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The DataTable %s is not a valid L10N Assets DataTable"), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		return nullptr;
	}
	FL10NAssetsTable* Row = InL10NData->FindRow<FL10NAssetsTable>(InRowName, TEXT("Row Name"), true);
	if (!Row)
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s is not found in DataTable %s"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		return nullptr;
	}
	FSoftObjectPath Result;
#pragma region Switch and return
	switch (InLanguage) {
	case ELanguage::English:
		Result=Row->English;
		break;
	case ELanguage::SimplifiedChinese:
		Result=Row->SimplifiedChinese;
		break;
	case ELanguage::TraditionalChinese:
		Result=Row->TraditionalChinese;
		break;
	case ELanguage::Japanese:
		Result=Row->Japanese;
		break;
	case ELanguage::Korean:
		Result=Row->Korean;
		break;
	case ELanguage::French:
		Result=Row->French;
		break;
	case ELanguage::German:
		Result=Row->German;
		break;
	case ELanguage::SpanishSpain:
		Result=Row->SpanishSpain;
		break;
	case ELanguage::SpanishLatinAmerica:
		Result=Row->SpanishLatinAmerica;
		break;
	case ELanguage::Italian:
		Result=Row->Italian;
		break;
	case ELanguage::Thai:
		Result=Row->Thai;
		break;
	case ELanguage::Bulgarian:
		Result=Row->Bulgarian;
		break;
	case ELanguage::Czech:
		Result=Row->Czech;
		break;
	case ELanguage::Danish:
		Result=Row->Danish;
		break;
	case ELanguage::Greek:
		Result=Row->Greek;
		break;
	case ELanguage::BahasaIndonesia:
		Result=Row->BahasaIndonesia;
		break;
	case ELanguage::Hungarian:
		Result=Row->Hungarian;
		break;
	case ELanguage::Dutch:
		Result=Row->Dutch;
		break;
	case ELanguage::Norwegian:
		Result=Row->Norwegian;
		break;
	case ELanguage::Polish:
		Result=Row->Polish;
		break;
	case ELanguage::PortugueseBrazil:
		Result=Row->PortugueseBrazil;
		break;
	case ELanguage::PortuguesePortugal:
		Result=Row->PortuguesePortugal;
		break;
	case ELanguage::Romanian:
		Result=Row->Romanian;
		break;
	case ELanguage::Russian:
		Result=Row->Russian;
		break;
	case ELanguage::Finnish:
		Result=Row->Finnish;
		break;
	case ELanguage::Swedish:
		Result=Row->Swedish;
		break;
	case ELanguage::Turkish:
		Result=Row->Turkish;
		break;
	case ELanguage::Vietnamese:
		Result=Row->Vietnamese;
		break;
	case ELanguage::Ukrainian:
		Result=Row->Ukrainian;
		break;
	}
#pragma endregion
	if (Result.IsNull())
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not support language %s"), *InRowName.ToString(), *InL10NData->GetName(), ELanguageToString(InLanguage));
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] Try to rise the default language result"));
#pragma region Switch and return
		switch (GetDefaultLanguage(WorldContextObject)) {
		case ELanguage::English:
			Result=Row->English;
			break;
		case ELanguage::SimplifiedChinese:
			Result=Row->SimplifiedChinese;
			break;
		case ELanguage::TraditionalChinese:
			Result=Row->TraditionalChinese;
			break;
		case ELanguage::Japanese:
			Result=Row->Japanese;
			break;
		case ELanguage::Korean:
			Result=Row->Korean;
			break;
		case ELanguage::French:
			Result=Row->French;
			break;
		case ELanguage::German:
			Result=Row->German;
			break;
		case ELanguage::SpanishSpain:
			Result=Row->SpanishSpain;
			break;
		case ELanguage::SpanishLatinAmerica:
			Result=Row->SpanishLatinAmerica;
			break;
		case ELanguage::Italian:
			Result=Row->Italian;
			break;
		case ELanguage::Thai:
			Result=Row->Thai;
			break;
		case ELanguage::Bulgarian:
			Result=Row->Bulgarian;
			break;
		case ELanguage::Czech:
			Result=Row->Czech;
			break;
		case ELanguage::Danish:
			Result=Row->Danish;
			break;
		case ELanguage::Greek:
			Result=Row->Greek;
			break;
		case ELanguage::BahasaIndonesia:
			Result=Row->BahasaIndonesia;
			break;
		case ELanguage::Hungarian:
			Result=Row->Hungarian;
			break;
		case ELanguage::Dutch:
			Result=Row->Dutch;
			break;
		case ELanguage::Norwegian:
			Result=Row->Norwegian;
			break;
		case ELanguage::Polish:
			Result=Row->Polish;
			break;
		case ELanguage::PortugueseBrazil:
			Result=Row->PortugueseBrazil;
			break;
		case ELanguage::PortuguesePortugal:
			Result=Row->PortuguesePortugal;
			break;
		case ELanguage::Romanian:
			Result=Row->Romanian;
			break;
		case ELanguage::Russian:
			Result=Row->Russian;
			break;
		case ELanguage::Finnish:
			Result=Row->Finnish;
			break;
		case ELanguage::Swedish:
			Result=Row->Swedish;
			break;
		case ELanguage::Turkish:
			Result=Row->Turkish;
			break;
		case ELanguage::Vietnamese:
			Result=Row->Vietnamese;
			break;
		case ELanguage::Ukrainian:
			Result=Row->Ukrainian;
			break;
		}
#pragma endregion
	}
	return Result;
}

/**
 * Get L10N Art Texture from DataTable will call GetL10NArtSoftObjectPath
 * @brief If the row cannot find a not null FSoftObjectPath by GetL10NArtSoftObjectPath, it will try to return the default language row and load it as a UTexture2D.
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Art DataTable
 * @param InLanguage : Language
 * @param WorldContextObject : World Context Object
 * @return UTexture2D : If the L10N Assets SoftObjectPath is a valid UTexture2D, it will return the UTexture2D, otherwise it will return nullptr.
 */
UTexture2D* UL10NBlueprintLibrary::GetL10NTextureFromAssetsData(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UObject* WorldContextObject)
{
	UObject* Object = GetL10NAssetsSoftObjectPath(InRowName, InL10NData, InLanguage, WorldContextObject).TryLoad();
	if (UTexture2D* Texture = Cast<UTexture2D>(Object))
	{
		return Texture;
	}
	return nullptr;
}

/**
 * Get L10N Art Audio from DataTable will call GetL10NArtSoftObjectPath
 * @brief If the row cannot find a not null FSoftObjectPath by GetL10NArtSoftObjectPath, it will try to return the default language row and load it as a USoundCue.
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Art DataTable
 * @param InLanguage : Language
 * @param WorldContextObject : World Context Object
 * @return USoundCue : If the L10N Assets SoftObjectPath is a valid USoundCue, it will return the USoundCue, otherwise it will return nullptr.
 */
USoundCue* UL10NBlueprintLibrary::GetL10NAudioFromAssetsData(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UObject* WorldContextObject)
{
	UObject* Object = GetL10NAssetsSoftObjectPath(InRowName, InL10NData, InLanguage, WorldContextObject).TryLoad();
	if (USoundCue* SoundCue = Cast<USoundCue>(Object))
	{
		return SoundCue;
	}
	return nullptr;
}

UDialogueWave* UL10NBlueprintLibrary::GetL10NDialogueFromAssetsData(const FName& InRowName,
	const UDataTable* InL10NData, const ELanguage InLanguage, UObject* WorldContextObject)
{
	UObject* Object = GetL10NAssetsSoftObjectPath(InRowName, InL10NData, InLanguage,WorldContextObject).TryLoad();
	if (UDialogueWave* DialogueWave = Cast<UDialogueWave>(Object))
	{
		return DialogueWave;
	}
	return nullptr;
}

void UL10NBlueprintLibrary::SetTextWithL10N(UObject* WorldContextObject,UWidget* InWidget, const FName& InRowName, const UDataTable* InL10NData,
                                            const ELanguage InLanguage)
{
	if (UTextBlock* TextBlock = Cast<UTextBlock>(InWidget))
	{
		TextBlock->SetText(GetL10NPlainText(InRowName, InL10NData, InLanguage,WorldContextObject));
	}
	else if (URichTextBlock* RichTextBlock = Cast<URichTextBlock>(InWidget))
	{
		RichTextBlock->SetText(GetL10NPlainText(InRowName, InL10NData, InLanguage,WorldContextObject));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Widget %s is not a TextBlock or RichTextBlock"), *InWidget->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
	}
}

void UL10NBlueprintLibrary::PlaySound2DWithL10N(const FName& InRowName, const UDataTable* InL10NData,
                                                const ELanguage InLanguage, UObject* WorldContextObject, float VolumeMultiplier, float PitchMultiplier,
                                                float StartTime, USoundConcurrency* ConcurrencySettings, const AActor* OwningActor, bool bIsUISound)
{
	if (USoundCue* SoundCue = GetL10NAudioFromAssetsData(InRowName, InL10NData, InLanguage,WorldContextObject))
	{
		UGameplayStatics::PlaySound2D(WorldContextObject, SoundCue, VolumeMultiplier, PitchMultiplier, StartTime, ConcurrencySettings, OwningActor, bIsUISound);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not a valid USoundCue"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
	}
}

void UL10NBlueprintLibrary::PlaySoundAtLocationWithL10N(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UObject* WorldContextObject, FVector Location,
	FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime,
	class USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, const AActor* OwningActor,
	const UInitialActiveSoundParams* InitialParams)
{
	if (USoundCue* SoundCue = GetL10NAudioFromAssetsData(InRowName, InL10NData, InLanguage,WorldContextObject))
	{
		UGameplayStatics::PlaySoundAtLocation(WorldContextObject, SoundCue, Location, Rotation, VolumeMultiplier, PitchMultiplier, StartTime, AttenuationSettings, ConcurrencySettings, OwningActor, InitialParams);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not a valid USoundCue"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
	}
}

void UL10NBlueprintLibrary::PlayDialogue2DWithL10N(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UDialogueVoice* Speaker, TArray<UDialogueVoice*> Targets,
	 UObject* WorldContextObject, float VolumeMultiplier, float PitchMultiplier,
	float StartTime)
{
	if (UDialogueWave* DialogueWave = GetL10NDialogueFromAssetsData(InRowName, InL10NData, InLanguage,WorldContextObject))
	{
		FDialogueContext* TempContext = new FDialogueContext();
		TempContext->Speaker = Speaker;
		TempContext->Targets = Targets;
		UGameplayStatics::PlayDialogue2D(WorldContextObject, DialogueWave, *TempContext, VolumeMultiplier, PitchMultiplier, StartTime);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not a valid UDialogueWave"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
	}
}

void UL10NBlueprintLibrary::PlayDialogueAtLocationWithL10N(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UDialogueVoice* Speaker, TArray<UDialogueVoice*> Targets,
	UObject* WorldContextObject, FVector Location, FRotator Rotation, float VolumeMultiplier,
	float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings)
{
	if (UDialogueWave* DialogueWave = GetL10NDialogueFromAssetsData(InRowName, InL10NData, InLanguage, WorldContextObject))
	{
		FDialogueContext* TempContext = new FDialogueContext();
		TempContext->Speaker = Speaker;
		TempContext->Targets = Targets;
		UGameplayStatics::PlayDialogueAtLocation(WorldContextObject, DialogueWave, *TempContext, Location, Rotation, VolumeMultiplier, PitchMultiplier, StartTime, AttenuationSettings);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not a valid UDialogueWave"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
	}
}

void UL10NBlueprintLibrary::SetImageWithL10N(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage, UObject* WorldContextObject, UImage* InImage, const FSlateBrush& InBrushSetting)
{
	if (UTexture2D* Texture2D = GetL10NTextureFromAssetsData(InRowName, InL10NData, InLanguage,WorldContextObject))
	{
		FSlateBrush* TempBrush = new FSlateBrush();
		if (InBrushSetting != FSlateBrush())
		{
			TempBrush->ImageSize = InBrushSetting.ImageSize;
			TempBrush->DrawAs = InBrushSetting.DrawAs;
			TempBrush->Margin = InBrushSetting.Margin;
			TempBrush->TintColor = InBrushSetting.TintColor;
			TempBrush->Tiling = InBrushSetting.Tiling;
			TempBrush->DrawAs = InBrushSetting.DrawAs;
			TempBrush->Tiling = InBrushSetting.Tiling;
			TempBrush->OutlineSettings = InBrushSetting.OutlineSettings;
		}
		TempBrush->SetResourceObject(Texture2D);
		InImage->SetBrush(*TempBrush);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s in DataTable %s is not a valid UTexture2D"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
	}
}


/**
 * Get Supported Language
 * @return TArray<ELanguage> : Supported Language Array
 */
TArray<ELanguage> UL10NBlueprintLibrary::GetSupportedLanguage(UObject* WorldContextObject)
{
	if (ALocalizationManager* Manager = GetLocalizationManager(WorldContextObject))
	{
		return Manager->SupportedLanguage;;
	}
	if (UI18NToolSettings* Settings = GetI18NToolSettings())
	{
		return Settings->GetSupportedLanguage();
	}
	return {};
}

TArray<FString> UL10NBlueprintLibrary::GetSupportedLanguageNames(UObject* WorldContextObject)
{
	TArray<FString> Result;
	for (ELanguage Language : GetSupportedLanguage(WorldContextObject))
	{
		Result.Add(ELanguageToString(Language));
	}
	return Result;
}

TArray<FString> UL10NBlueprintLibrary::GetSupportedLanguagePureNames(UObject* WorldContextObject)
{
	TArray<FString> Result;
	for (ELanguage Language : GetSupportedLanguage(WorldContextObject))
	{
		FString* Temp = new FString();
		FString* Temp2 = new FString();
		FString(ELanguageToString(Language)).Split("(",Temp,Temp2);
		Result.Add(*Temp);
	}
	return Result;
}

/**
 * Get Current Global Language
 * @return ELanguage : Current Global Language or English if not found
 */
ELanguage UL10NBlueprintLibrary::GetCurrentGlobalLanguage(UObject* WorldContextObject)
{
	if (ALocalizationManager* Manager = GetLocalizationManager(WorldContextObject))
	{
		return Manager->CurrentGlobalLanguage;;
	}
	if (UI18NToolSettings* Settings = GetI18NToolSettings())
	{
		return Settings->CurrentGlobalLanguage;;
	}
	return ELanguage::English;
}

/**
 * Set Current Global Language
 * @param InLanguage : Language
 * @param WorldContextObject : World Context Object
 */
void UL10NBlueprintLibrary::SetCurrentGlobalLanguage(const ELanguage InLanguage,UObject* WorldContextObject)
{
	CheckSupport(InLanguage,WorldContextObject);
	if (ALocalizationManager* Manager = GetLocalizationManager(WorldContextObject))
	{
		Manager->RuntimeSetCurrentGlobalLanguage(InLanguage);
	}
	GetI18NToolSettings()->SetCurrentGlobalLanguage(InLanguage);
}
/**
 * Get Localization Manager
 * @return ALocalizationManager* : Localization Manager Instance
 */
ALocalizationManager* UL10NBlueprintLibrary::GetLocalizationManager(const UObject* WorldContextObject)
{
	if (ALocalizationedGameMode* GameMode = Cast<ALocalizationedGameMode>(UGameplayStatics::GetGameMode(WorldContextObject)))
	{
		return GameMode->GetLocalizationManagerInstance();
	}
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		for (TActorIterator<ALocalizationManager> It(World); It; ++It)
		{
			return *It;
		}
	}
	return nullptr;
}

/**
 * Check InLanguage is supported
 * @param InLanguage : Language
 */
void UL10NBlueprintLibrary::CheckSupport(const ELanguage InLanguage,UObject* WorldContextObject)
{
	if (!GetSupportedLanguage(WorldContextObject).Contains(InLanguage))
	{
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool] Try to get a unsupported language : %s"), ELanguageToString(InLanguage));
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool Hint] If you want support a language add SupportedLanguage in Project Settings -> Easy I18NTool -> Easy L10N Tool -> Supported Language"));
	}
}
/**
 * Convert ELanguage to String
 * @param InLanguage : Language
 * @return const TCHAR* : Language String
 */
const TCHAR* UL10NBlueprintLibrary::ELanguageToString(const ELanguage InLanguage)
{
	UEnum* EnumPtr = FindObject<UEnum>(nullptr, TEXT("/Script/I18NTool.ELanguage"), true);
	// Use for debug
	// UE_LOG(LogTemp, Warning, TEXT("Object Path: %s"), *EnumPtr->GetPathName());
	return *EnumPtr->GetDisplayNameTextByIndex(static_cast<int32>(InLanguage)).ToString();
}

/**
 * Get Default Language
 * @return ELanguage : Default Language or English if not found
 */
ELanguage UL10NBlueprintLibrary::GetDefaultLanguage(const UObject* WorldContextObject)
{
	if (ALocalizationManager* Manager = GetLocalizationManager(WorldContextObject))
	{
		return Manager->DefaultLanguage;;
	}
	if (UI18NToolSettings* Settings = GetI18NToolSettings())
	{
		return Settings->DefaultLanguage;;
	}
	return ELanguage::English;
}

UI18NToolSettings* UL10NBlueprintLibrary::GetI18NToolSettings()
{
	return GetMutableDefault<UI18NToolSettings>();
}
