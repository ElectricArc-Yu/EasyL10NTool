# EasyL10NTool

Easy Localization & Internationalization Tool Plugin For Unreal Engine.

---

@ Author : Electric Arc
@ Advise, Suggestion and Bug Report : Feel free to create Issue.

---

The advantages of this plugin:

* It is extremely easy to configure and use.
* The lightweight structure reduces the learning cost and the difficulty of use. 
* With extremely low invasiveness (It only requires inheriting parent class LocalizationedGameMode.), it can be more easily integrated into the running project. 
* Provides highly customizable basic localization data acquisition methods (Basic Getters).
* Provides methods to directly acquire data as Audio, Dialogue, or Texture2D.
* Provides direct usage methods called Quick Setters like Set Text With L10N.
* Provides Pure Getters for the configuration of currently supported languages (Incluede text return and enum return) and the current language.
* Provides a boradcast OnCurrentGlobalLanguageChanged.

---

# Buy my plugin on Unreal Engine Marketplace

- On Fab.com : 
- Buy me a coffee : 

# How to merge to your project

1. If you buy this plugin on Fab.com just install in Epic Games Launcher -> Unreal Engine -> Library -> Install to Engine. And then you can ignore remaining steps.
2. Download .zip file from [release page](https://github.com/ElectricArc-Yu/EasyL10NTool/releases/latest)
3. Unzip the downloaded file into your project's root folder to merge the plugin into your project.
4. Get choose using way :
   - Put LocalizationManagerActor into each level you want to use localization.
   - Inherit your GameMode from LocalizationedGameMode, and use that GameMode in each level you want to use localization.
5. Enjoy simple localization.

# Registering in current language changed

1. Call `GetLocalizationManager` in your Blueprint.
2. Bind `OnCurrentGlobalLanguageChanged` event to your function.

# How to create data for localization

1. Create a new Data Table in Unreal Engine.
2. Choose 'FL10NPlainTextTable' or ‘FL10NAssetsTable’ as the row type.
3. Create a spreadsheet with the following columns:
   - --- : The Data Table Row Name.
   - English : The English text of the data.
   - ... : The text of the data in other languages. (You can add as many columns as you want.)
4. Import the spreadsheet into the Data Table.
5. If you don't want to adapt with all languages listed in steam, you can remove them form column list. And set below options to true in created Data Table Detail page.
   - Ignore Missing Fields : true
   - Ignore Extra Fields : true

# Documentation

BlueprintLibrary : [L10NToolBlueprintLibrary](BPLDocumentation.md)