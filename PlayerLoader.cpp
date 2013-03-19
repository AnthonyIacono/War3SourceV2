#include "PlayerLoader.h"
#include "QueryDBThreadOperation.h"
#include "PLSelectQueryDBThreadOperationCallback.h"
#include <iostream>

namespace War3Source {
	PlayerLoader::PlayerLoader(const char *steamID, IPlayerLoaderCallback *callback) {
		strcpy_s(this->steamID, sizeof(this->steamID), steamID);
		this->callback = callback;
	}

	void PlayerLoader::LoadPlayer() {
		char playerSelectQuery[512];
		sprintf_s(playerSelectQuery, sizeof(playerSelectQuery), "SELECT * FROM `war3_players` WHERE `steamid` = '%s'", steamID);

		PLSelectQueryDBThreadOperationCallback *plSelectQueryDBThreadOperationCallback = new PLSelectQueryDBThreadOperationCallback(this);
		QueryDBThreadOperation *queryDBThreadOperation = new QueryDBThreadOperation(playerSelectQuery, plSelectQueryDBThreadOperationCallback);

		dbi->AddToThreadQueue(queryDBThreadOperation, PrioQueue_Normal);
	}

	const char *PlayerLoader::GetSteamID() {
		return this->steamID;
	}

	IPlayerLoaderCallback *PlayerLoader::GetCallback() {
		return this->callback;
	}
}