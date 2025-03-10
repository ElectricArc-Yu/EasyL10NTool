// Copyright Epic Games, Inc. All Rights Reserved.

#include "I18NTool.h"
#include "I18NToolStyle.h"
#include "I18NToolCommands.h"
#include "I18NToolSettings.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#endif
#include "Misc/MessageDialog.h"


#define LOCTEXT_NAMESPACE "FI18NToolModule"

void FI18NToolModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FI18NToolStyle::Initialize();
	FI18NToolStyle::ReloadTextures();

	FI18NToolCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	// PluginCommands->MapAction(
	// 	FI18NToolCommands::Get().PluginAction,
	// 	FExecuteAction::CreateRaw(this, &FI18NToolModule::PluginButtonClicked),
	// 	FCanExecuteAction());

	//UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FI18NToolModule::RegisterMenus));

	// Registering the settings
#if WITH_EDITOR
	if (ISettingsModule* I18NToolModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		I18NToolModule->RegisterSettings("Project", "EasyL10NTool", "General",
		                                 LOCTEXT("RuntimeGeneralSettingsName", "Easy L10N Tool"),
		                                 LOCTEXT("RuntimeGeneralSettingsDescription",
		                                         "Configure the Easy L10N Tool settings"),
		                                 GetMutableDefault<UI18NToolSettings>()
		);
	}
#endif
}

void FI18NToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FI18NToolStyle::Shutdown();

	FI18NToolCommands::Unregister();

#if WITH_EDITOR
	if (ISettingsModule* I18NToolModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		I18NToolModule->UnregisterSettings("Project", "EasyL10NTool", "General");
	}
#endif
}

// void FI18NToolModule::PluginButtonClicked()
// {
// 	// Put your "OnButtonClicked" stuff here
// 	FText DialogText = FText::Format(
// 							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
// 							FText::FromString(TEXT("FI18NToolModule::PluginButtonClicked()")),
// 							FText::FromString(TEXT("I18NTool.cpp"))
// 					   );
// 	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
// }
//
// void FI18NToolModule::RegisterMenus()
// {
// 	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
// 	FToolMenuOwnerScoped OwnerScoped(this);
//
// 	{
// 		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
// 		{
// 			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
// 			Section.AddMenuEntryWithCommandList(FI18NToolCommands::Get().PluginAction, PluginCommands);
// 		}
// 	}
//
// 	{
// 		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
// 		{
// 			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
// 			{
// 				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FI18NToolCommands::Get().PluginAction));
// 				Entry.SetCommandList(PluginCommands);
// 			}
// 		}
// 	}
// }

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FI18NToolModule, I18NTool)
