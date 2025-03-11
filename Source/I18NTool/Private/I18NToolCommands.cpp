// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025

#include "I18NToolCommands.h"

#define LOCTEXT_NAMESPACE "FI18NToolModule"

void FI18NToolCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "I18NTool", "Execute I18NTool action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
