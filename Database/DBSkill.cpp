#include "DBSkill.h"
#include "Utils.h"

namespace War3Source {
	DBSkill::DBSkill(unsigned int id, unsigned int characterId, const char *className, unsigned int level) {
		this->id = id;
		this->characterId = characterId;
		StrCopy(this->className, sizeof(this->className), className);
		this->level = level;
	}

	DBSkill::~DBSkill() {
	}

	void DBSkill::Destroy() {
		delete this;
	}

	unsigned int DBSkill::GetID() {
		return this->id;
	}

	unsigned int DBSkill::GetCharacterID() {
		return this->characterId;
	}

	const char *DBSkill::GetClass() {
		return this->className;
	}

	unsigned int DBSkill::GetLevel() {
		return this->level;
	}
}