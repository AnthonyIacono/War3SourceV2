#include "DBPlayer.h"
#include "Utils.h"

namespace War3Source {
	DBPlayer::DBPlayer(unsigned int id, const char *steamID, unsigned int activeCharacterID) {
		this->id = id;
		StrCopy(this->steamID, sizeof(this->steamID), steamID);
		this->activeCharacterID = activeCharacterID;
	}

	DBPlayer::~DBPlayer() {
	}

	void DBPlayer::Destroy() {
		delete this;
	}
	
	unsigned int DBPlayer::GetID() {
		return this->id;
	}

	const char *DBPlayer::GetSteamID() {
		return this->steamID;
	}
	
	unsigned int DBPlayer::GetActiveCharacterID() {
		return this->activeCharacterID;
	}
}