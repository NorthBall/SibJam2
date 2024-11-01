// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SibJam2 : ModuleRules
{
	public SibJam2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
