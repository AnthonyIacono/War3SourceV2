#include "DatabaseSkill.h"
#include <iostream>

namespace War3Source {
	DatabaseSkill::DatabaseSkill(unsigned int id, unsigned int characterId, const char *className, unsigned int level) {
		this->id = id;
		this->characterId = characterId;
		strcpy_s(this->className, sizeof(this->className), className);
		this->level = level;
	}

	DatabaseSkill::~DatabaseSkill() {
	}

	void DatabaseSkill::Destroy() {
		delete this;
	}

	unsigned int DatabaseSkill::GetID() {
		return this->id;
	}

	unsigned int DatabaseSkill::GetCharacterID() {
		return this->characterId;
	}

	const char *DatabaseSkill::GetClass() {
		return this->className;
	}

	unsigned int DatabaseSkill::GetLevel() {
		return this->level;
	}
}