#if defined _war3source_degugmode_included
 #endinput
#endif
#define _war3source_degugmode_included

#include "War3Source_ConVars"

InitializeDebugMode() {
	DebugPrint("Debug mode initialized.");
}

DebugPrint(const String:format[], any:...) {
	if(!GetConVarBool(g_CVarDebug)) {
		return;
	}
	
	decl String:output[1024];
	
	VFormat(output, sizeof(output), format, 2);
	
	Format(output, sizeof(output), "[W3DEBUG] %s", output);
	
	PrintToServer("%s", output);
}