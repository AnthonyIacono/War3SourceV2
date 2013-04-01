#include "DatabasePlayer.h"
#include <iostream>

namespace War3Source {
	DatabasePlayer::DatabasePlayer(unsigned int id, const char *steamID, unsigned int activeCharacterID) {
		this->id = id;
		strcpy_s(this->steamID, sizeof(this->steamID), steamID);
		this->activeCharacterID = activeCharacterID;
	}

	DatabasePlayer::~DatabasePlayer() {
	}

	void DatabasePlayer::Destroy() {
		delete this;
	}
	
	unsigned int DatabasePlayer::GetID() {
		return this->id;
	}

	const char *DatabasePlayer::GetSteamID() {
		return this->steamID;
	}
	
	unsigned int DatabasePlayer::GetActiveCharacterID() {
		return this->activeCharacterID;
	}
}