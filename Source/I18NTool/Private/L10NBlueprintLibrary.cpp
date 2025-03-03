// Fill out your copyright notice in the Description page of Project Settings.

#include "L10NBlueprintLibrary.h"

#include "L10NEnums.h"
#include "I18NToolSettings.h"
#include "L10NStructs.h"

UL10NBlueprintLibrary::UL10NBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}
/**
 * Get L10N Plain Text from DataTable
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Plain Text DataTable
 * @param InLanguage : Language
 * @return FText : L10N Plain Text or "Bad DataTable" in InL10NData is not a valid L10N Plain Text DataTable or "Cannot Find Row" in InRowName is not found in InL10NData Row Name.
 */
FText UL10NBlueprintLibrary::GetL10NPlainText(const FName& InRowName, const UDataTable* InL10NData,
                                         const ELanguage InLanguage)
{
	if (!GetSupportedLanguage().Contains(InLanguage))
	{
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool] Try to get a unsupported language : %s"), *FindObject<UEnum>(ANY_PACKAGE, TEXT("ELanguage"), true)->GetDisplayNameTextByIndex(
			       static_cast<int32>(InLanguage)).ToString());
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
#pragma region Switch and return
	switch (InLanguage) {
	case ELanguage::English:
		return Row->English;
	case ELanguage::SimplifiedChinese:
		return Row->SimplifiedChinese;
	case ELanguage::TraditionalChinese:
		return Row->TraditionalChinese;
	case ELanguage::Japanese:
		return Row->Japanese;
	case ELanguage::Korean:
		return Row->Korean;
	case ELanguage::French:
		return Row->French;
	case ELanguage::German:
		return Row->German;
	case ELanguage::SpanishSpain:
		return Row->SpanishSpain;
	case ELanguage::SpanishLatinAmerica:
		return Row->SpanishLatinAmerica;
	case ELanguage::Italian:
		return Row->Italian;
	case ELanguage::Thai:
		return Row->Thai;
	case ELanguage::Bulgarian:
		return Row->Bulgarian;
	case ELanguage::Czech:
		return Row->Czech;
	case ELanguage::Danish:
		return Row->Danish;
	case ELanguage::Greek:
		return Row->Greek;
	case ELanguage::BahasaIndonesia:
		return Row->BahasaIndonesia;
	case ELanguage::Hungarian:
		return Row->Hungarian;
	case ELanguage::Dutch:
		return Row->Dutch;
	case ELanguage::Norwegian:
		return Row->Norwegian;
	case ELanguage::Polish:
		return Row->Polish;
	case ELanguage::PortugueseBrazil:
		return Row->PortugueseBrazil;
	case ELanguage::PortuguesePortugal:
		return Row->PortuguesePortugal;
	case ELanguage::Romanian:
		return Row->Romanian;
	case ELanguage::Russian:
		return Row->Russian;
	case ELanguage::Finnish:
		return Row->Finnish;
	case ELanguage::Swedish:
		return Row->Swedish;
	case ELanguage::Turkish:
		return Row->Turkish;
	case ELanguage::Vietnamese:
		return Row->Vietnamese;
	case ELanguage::Ukrainian:
		return Row->Ukrainian;
	default:
		// Illegal in-value
			return FText::GetEmpty();
	}
#pragma endregion
}



/**
 * Get L10N Art SoftObjectPath from DataTable
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Art DataTable
 * @param InLanguage : Language
 * @return FSoftObjectPath : L10N Art SoftObjectPath or nullptr in InL10NData is not a valid L10N Art DataTable or "Cannot Find Row" in InRowName is not found in InL10NData Row Name.
 */
FSoftObjectPath UL10NBlueprintLibrary::GetL10NArtSoftObjectPath(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage)
{
	CheckSupport(InLanguage);
	if (InL10NData->GetRowStruct() != FL10NArtTable::StaticStruct())
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The DataTable %s is not a valid L10N Art DataTable"), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		return nullptr;
	}
	FL10NArtTable* Row = InL10NData->FindRow<FL10NArtTable>(InRowName, TEXT("Row Name"), true);
	if (!Row)
	{
		UE_LOG(LogTemp, Error, TEXT("[L10NTool] The Row %s is not found in DataTable %s"), *InRowName.ToString(), *InL10NData->GetName());
		UE_LOG(LogTemp, Error, TEXT("[CallStack] \n%s[StackEnd]"),*FFrame::GetScriptCallstack());
		return nullptr;
	}
#pragma region Switch and return
	switch (InLanguage)
	{
	case ELanguage::English:
		return Row->English;
	case ELanguage::SimplifiedChinese:
		return Row->SimplifiedChinese;
	case ELanguage::TraditionalChinese:
		return Row->TraditionalChinese;
	case ELanguage::Japanese:
		return Row->Japanese;
	case ELanguage::Korean:
		return Row->Korean;
	case ELanguage::French:
		return Row->French;
	case ELanguage::German:
		return Row->German;
	case ELanguage::SpanishSpain:
		return Row->SpanishSpain;
	case ELanguage::SpanishLatinAmerica:
		return Row->SpanishLatinAmerica;
	case ELanguage::Italian:
		return Row->Italian;
	case ELanguage::Thai:
		return Row->Thai;
	case ELanguage::Bulgarian:
		return Row->Bulgarian;
	case ELanguage::Czech:
		return Row->Czech;
	case ELanguage::Danish:
		return Row->Danish;
	case ELanguage::Greek:
		return Row->Greek;
	case ELanguage::BahasaIndonesia:
		return Row->BahasaIndonesia;
	case ELanguage::Hungarian:
		return Row->Hungarian;
	case ELanguage::Dutch:
		return Row->Dutch;
	case ELanguage::Norwegian:
		return Row->Norwegian;
	case ELanguage::Polish:
		return Row->Polish;
	case ELanguage::PortugueseBrazil:
		return Row->PortugueseBrazil;
	case ELanguage::PortuguesePortugal:
		return Row->PortuguesePortugal;
	case ELanguage::Romanian:
		return Row->Romanian;
	case ELanguage::Russian:
		return Row->Russian;
	case ELanguage::Finnish:
		return Row->Finnish;
	case ELanguage::Swedish:
		return Row->Swedish;
	case ELanguage::Turkish:
		return Row->Turkish;
	case ELanguage::Vietnamese:
		return Row->Vietnamese;
	case ELanguage::Ukrainian:
		return Row->Ukrainian;
	default:
		// Illegal in-value
			return nullptr;
	}
#pragma endregion 
}

/**
 * Get L10N Art Texture from DataTable will call GetL10NArtSoftObjectPath
 * @param InRowName : Row Name
 * @param InL10NData : Must be a valid L10N Art DataTable
 * @param InLanguage : Language
 * @return UTexture2D : L10N Art Texture or nullptr in InL10NData is not a valid L10N Art DataTable or "Cannot Find Row" in InRowName is not found in InL10NData Row Name.
 */
UTexture2D* UL10NBlueprintLibrary::GetL10NArtTexture(const FName& InRowName, const UDataTable* InL10NData,
	const ELanguage InLanguage)
{
	UObject* Object = GetL10NArtSoftObjectPath(InRowName, InL10NData, InLanguage).TryLoad();
	if (UTexture2D* Texture = Cast<UTexture2D>(Object))
	{
		return Texture;
	}
	return nullptr;
}

/**
 * Get Supported Language
 * @return TArray<ELanguage> : Supported Language Array
 */
TArray<ELanguage> UL10NBlueprintLibrary::GetSupportedLanguage()
{
	if (UI18NToolSettings* Settings = GetMutableDefault<UI18NToolSettings>())
	{
		return Settings->GetSupportedLanguage();
	}
	return TArray<ELanguage>();
}
/**
 * Get Current Global Language
 * @return ELanguage : Current Global Language or English if not found
 */
ELanguage UL10NBlueprintLibrary::GetCurrentGlobalLanguage()
{
	if (UI18NToolSettings* Settings = GetMutableDefault<UI18NToolSettings>())
	{
		return Settings->GetCurrentGlobalLanguage();
	}
	return ELanguage::English;
}

/**
 * Set Current Global Language
 * @param InLanguage : Language
 */
void UL10NBlueprintLibrary::SetCurrentGlobalLanguage(const ELanguage InLanguage)
{
	CheckSupport(InLanguage);
	if (UI18NToolSettings* Settings = GetMutableDefault<UI18NToolSettings>())
	{
		Settings->SetCurrentGlobalLanguage(InLanguage);
	}
}
/**
 * Check InLanguage is supported
 * @param InLanguage : Language
 */
void UL10NBlueprintLibrary::CheckSupport(const ELanguage InLanguage)
{
	if (!GetSupportedLanguage().Contains(InLanguage))
	{
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool] Try to get a unsupported language : %s"), *FindObject<UEnum>(ANY_PACKAGE, TEXT("ELanguage"), true)->GetDisplayNameTextByIndex(
				   static_cast<int32>(InLanguage)).ToString());
		UE_LOG(LogTemp, Warning, TEXT("[L10NTool Hint] If you want support a language add SupportedLanguage in Project Settings -> Easy I18NTool -> Easy L10N Tool -> Supported Language"));
	}
}
