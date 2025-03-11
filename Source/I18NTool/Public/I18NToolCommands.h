// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025

#pragma once

#include "Framework/Commands/Commands.h"
#include "I18NToolStyle.h"

class FI18NToolCommands : public TCommands<FI18NToolCommands>
{
public:
	FI18NToolCommands()
		: TCommands<FI18NToolCommands>(TEXT("I18NTool"), NSLOCTEXT("Contexts", "I18NTool", "I18NTool Plugin"),
		                               NAME_None, FI18NToolStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> PluginAction;
};
