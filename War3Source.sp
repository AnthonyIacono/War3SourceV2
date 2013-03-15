/**
 * Main file for War3Source.
 */

#include <sourcemod>
#include <smlib>

#include "War3Source_ConVars"
#include "War3Source_DebugMode"
#include "War3Source_Database"

public OnPluginStart() {
	InitializeConsoleVariables();
	InitializeDebugMode();
	InitializeDatabase();
	
	QueueAllPlayerLoads();
}

public OnClientPutInServer(clientIndex) {
	TryQueuePlayerLoad(clientIndex);
}

public OnClientAuthorized(clientIndex, const String:authString[]) {
	TryQueuePlayerLoad(clientIndex);
}