// Fill out your copyright notice in the Description page of Project Settings.


#include "I18NToolSettings.h"
#include "Misc/MessageDialog.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

void UI18NToolSettings::SetCurrentGlobalLanguage(const ELanguage InLanguage)
{
	CurrentGlobalLanguage = InLanguage;
}


void UI18NToolSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FString Name = PropertyChangedEvent.Property->GetName();
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(
		UI18NToolSettings, SupportedLanguage))
	{
		if (SupportedLanguage.IsEmpty())
		{
			SupportedLanguage.Add(ELanguage::English);
			FMessageDialog::Open(EAppMsgType::Ok,
			                     FText::FromString(
				                     TEXT("At least one language must be supported. English is added by default.")));
		}
		TSet<ELanguage> UniqueLanguages;
		for (int32 i = 0; i < (SupportedLanguage.Num() >= 28 ? 28 : SupportedLanguage.Num()); ++i)
		{
			if (!UniqueLanguages.Contains(SupportedLanguage[i]))
			{
				UniqueLanguages.Add(SupportedLanguage[i]);
			}
			else
			{
				// Replace with the next available enum value
				for (int32 EnumIndex = 0; EnumIndex < static_cast<int32>(ELanguage::Ukrainian); ++EnumIndex)
				{
					ELanguage NextLanguage = static_cast<ELanguage>(EnumIndex);
					if (!UniqueLanguages.Contains(NextLanguage))
					{
						SupportedLanguage[i] = NextLanguage;
						UniqueLanguages.Add(NextLanguage);
						break;
					}
				}
			}
		}

		if (SupportedLanguage.Num() > 28)
		{
			for (int i = SupportedLanguage.Num() - 1; i >= 28; --i)
			{
				SupportedLanguage.RemoveAt(i);
			}
			FMessageDialog::Open(EAppMsgType::Ok,
			                     FText::FromString(TEXT("All languages are supported, no duplicates allowed.")));
		}
	}
}
