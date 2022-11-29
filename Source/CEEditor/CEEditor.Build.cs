using UnrealBuildTool;

public class CEEditor : ModuleRules
{
	public CEEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"Engine",
					"CoreUObject",
					"InputCore",
					"LevelEditor",
					"Slate",
					"EditorStyle",
					"AssetTools",
					"EditorWidgets",
					"UnrealEd",
					"BlueprintGraph",
					"AnimGraph",
					"ComponentVisualizers",
					"CE"
			}
			);


	PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"AppFramework",
					"SlateCore",
					"AnimGraph",
					"UnrealEd",
					"KismetWidgets",
					"MainFrame",
					"PropertyEditor",
					"ComponentVisualizers",
					"CE"
				}
				);
	
	}
}