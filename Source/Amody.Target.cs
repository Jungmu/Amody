// Copyright JJ 2017-

using UnrealBuildTool;
using System.Collections.Generic;

public class AmodyTarget : TargetRules
{
	public AmodyTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Amody" } );
	}
}
