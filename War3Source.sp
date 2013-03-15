#include <sourcemod>
#include <smlib>

#include "War3Source_DebugMode"
#include "War3Source_ConVars"
#include "War3Source_Database"

public OnPluginStart() {
	InitializeDebugMode();
	InitializeConsoleVariables();
	InitializeDatabase();
	
	for(new clientIndex = 1; clientIndex <= MaxClients; clientIndex++) {
		if(!Client_IsIngameAuthorized(clientIndex)) {
			continue;
		}
		
		QueuePlayerLoad(clientIndex);
	}
}