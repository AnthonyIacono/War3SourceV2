#if defined _war3source_convars_included
 #endinput
#endif
#define _war3source_convars_included

new Handle:g_CVarDebug = INVALID_HANDLE;
new Handle:g_CVarVersion = INVALID_HANDLE;

InitializeConsoleVariables() {
	g_CVarVersion = CreateConVar("war3_version", "2.0alpha", "Current version of War3Source.", FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_REPLICATED|FCVAR_NOTIFY|FCVAR_DONTRECORD);
	g_CVarDebug = CreateConVar("war3_debug_mode", "1", "Whether or not debug mode is enabled.");
	
	DebugPrint("Console variables initialized.");
}