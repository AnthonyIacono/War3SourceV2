#include "DBQuest.h"
#include "Utils.h"

namespace War3Source {
	DBQuest::DBQuest(unsigned int id, unsigned int characterId, const char *className, const char *data) {
		this->id = id;
		this->characterId = characterId;
		StrCopy(this->className, sizeof(this->className), className);
		StrCopy(this->data, sizeof(this->data), data);
	}

	DBQuest::~DBQuest() {
	}

	void DBQuest::Destroy() {
		delete this;
	}

	unsigned int DBQuest::GetID() {
		return this->id;
	}

	unsigned int DBQuest::GetCharacterID() {
		return this->characterId;
	}

	const char *DBQuest::GetClass() {
		return this->className;
	}

	const char *DBQuest::GetData() {
		return this->data;
	}
}