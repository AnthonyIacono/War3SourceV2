#include "DatabaseCharacter.h"
#include <iostream>

namespace War3Source {
	DatabaseCharacter::DatabaseCharacter(unsigned int id, unsigned int playerID, const char *className, const char *name, unsigned int level, unsigned int xp) {
		this->id = id;
		this->playerID = playerID;
		strcpy_s(this->className, sizeof(this->className), className);
		strcpy_s(this->name, sizeof(this->name), name);
		this->level = level;
		this->xp = xp;
	}

	DatabaseCharacter::~DatabaseCharacter() {
	}

	void DatabaseCharacter::Destroy() {
		delete this;
	}

	unsigned int DatabaseCharacter::GetID() {
		return this->id;
	}

	unsigned int DatabaseCharacter::GetPlayerID() {
		return this->playerID;
	}

	const char *DatabaseCharacter::GetClass() {
		return this->className;
	}

	const char *DatabaseCharacter::GetName() {
		return this->name;
	}

	unsigned int DatabaseCharacter::GetLevel() {
		return this->level;
	}

	unsigned int DatabaseCharacter::GetXP() {
		return this->xp;
	}
}