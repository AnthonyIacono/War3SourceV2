#if defined _war3source_database_included
 #endinput
#endif
#define _war3source_database_included

new Handle:g_DatabaseConnection = INVALID_HANDLE;
new Handle:g_PlayerLoadQueue = INVALID_HANDLE;

InitializeDatabase() {
	g_PlayerLoadQueue = CreateArray();
	
	decl String:dbConfig[64] = "default";
	
	if(SQL_CheckConfig("war3source")) {
		Format(dbConfig, sizeof(dbConfig), "%s", "war3source");
	}
	
	SQL_TConnect(DBConnectionCallback, dbConfig);
}

public DBConnectionCallback(Handle:owner, Handle:db, const String:error[], any:data) {
	if(db == INVALID_HANDLE) {
		SetFailState("%s", "Failed to connect to database, adjust your config to include either \"war3source\" or \"default\".");
		return;
	}
	
	g_DatabaseConnection = db;
	
	DebugPrint("Successfully connected to database.");
	
	// Once we connect to the DB we need to go through the queue and process it.
	new queueSize = GetArraySize(g_PlayerLoadQueue);
	
	for(new queueIndex = 0; queueIndex < queueSize; queueIndex++) {
		new queueItemClientIndex = GetArrayCell(g_PlayerLoadQueue, queueIndex);
		
		LoadPlayer(queueItemClientIndex);
	}
	
	ClearArray(g_PlayerLoadQueue);
}

LoadPlayer(clientIndex) {
	DebugPrint("Loading client: %d", clientIndex);
}

IsPlayerLoadQueued(clientIndex) {
	new queueSize = GetArraySize(g_PlayerLoadQueue);
	
	for(new queueIndex = 0; queueIndex < queueSize; queueIndex++) {
		new queueItemClientIndex = GetArrayCell(g_PlayerLoadQueue, queueIndex);
		
		if(queueItemClientIndex != clientIndex) {
			continue;
		}
		
		return true;
	}
	
	return false;
}

QueuePlayerLoad(clientIndex) {
	if(IsPlayerLoadQueued(clientIndex)) {
		return;
	}
	
	PushArrayCell(g_PlayerLoadQueue, clientIndex);
	
	if(g_DatabaseConnection == INVALID_HANDLE) {
		return;
	}
	
	DequeuePlayerLoad(clientIndex);
	LoadPlayer(clientIndex);
}

DequeuePlayerLoad(clientIndex) {
	new queueSize = GetArraySize(g_PlayerLoadQueue);
	
	for(new queueIndex = 0; queueIndex < queueSize; queueIndex++) {
		new queueItemClientIndex = GetArrayCell(g_PlayerLoadQueue, queueIndex);
		
		if(queueItemClientIndex != clientIndex) {
			continue;
		}
		
		RemoveFromArray(g_PlayerLoadQueue, queueIndex);
		return;
	}
}

QueueAllPlayerLoads() {
	for(new clientIndex = 1; clientIndex <= MaxClients; clientIndex++) {
		if(!Client_IsIngameAuthorized(clientIndex)) {
			continue;
		}
		
		QueuePlayerLoad(clientIndex);
	}
}

TryQueuePlayerLoad(clientIndex) {
	if(!Client_IsIngameAuthorized(clientIndex)) {
		return;
	}
	
	QueuePlayerLoad(clientIndex);
}