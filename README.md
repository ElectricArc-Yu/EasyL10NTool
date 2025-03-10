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

# Documentation

BlueprintLibrary : [L10NToolBlueprintLibrary](BPLDocumentation.md)