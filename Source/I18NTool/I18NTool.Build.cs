// Copyright YuChenhaoran,  All Rights Reserved. publish in 2025
using UnrealBuildTool;

public class I18NTool : ModuleRules
{
	public I18NTool(ReadOnlyTargetRules Target) : base(Target)
	{
		// 禁用预编译头文件
		PCHUsage = PCHUsageMode.Default;
		PrivatePCHHeaderFile = "Public/I18NTool.h";

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);

		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"UMG"
				// ... add other public dependencies that you statically link with here ...
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"Projects",
				"InputCore",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore"
				// ... add private dependencies that you statically link with here ...	
			}
		);

		if (Target.bBuildEditor) PrivateDependencyModuleNames.AddRange(new[]
		{
			"Settings",
			"EditorFramework", 
			"UnrealEd", 
			"EditorStyle", 
			"Kismet" , 
			"EditorSubsystem"
		});

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		PrivateIncludePathModuleNames.AddRange(new[] { "I18NTool" });
	}
}