// Copyright JJ 2017-

using UnrealBuildTool;
using System.Collections.Generic;

public class AmodyEditorTarget : TargetRules
{
	public AmodyEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Amody" } );
	}
}
