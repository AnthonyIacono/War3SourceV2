#include "DBCharacter.h"
#include <iostream>

namespace War3Source {
	DBCharacter::DBCharacter(unsigned int id, unsigned int playerID, const char *className, const char *name, unsigned int level, unsigned int xp) {
		this->id = id;
		this->playerID = playerID;
		strcpy_s(this->className, sizeof(this->className), className);
		strcpy_s(this->name, sizeof(this->name), name);
		this->level = level;
		this->xp = xp;
	}

	DBCharacter::~DBCharacter() {
	}

	void DBCharacter::Destroy() {
		delete this;
	}

	unsigned int DBCharacter::GetID() {
		return this->id;
	}

	unsigned int DBCharacter::GetPlayerID() {
		return this->playerID;
	}

	const char *DBCharacter::GetClass() {
		return this->className;
	}

	const char *DBCharacter::GetName() {
		return this->name;
	}

	unsigned int DBCharacter::GetLevel() {
		return this->level;
	}

	unsigned int DBCharacter::GetXP() {
		return this->xp;
	}
}