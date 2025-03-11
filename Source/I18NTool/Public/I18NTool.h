// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025

#pragma once

#include "Modules/ModuleManager.h"


class FToolBarBuilder;
class FMenuBuilder;

class FI18NToolModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	//void PluginButtonClicked();

	//void RegisterMenus();

	TSharedPtr<class FUICommandList> PluginCommands;
};
