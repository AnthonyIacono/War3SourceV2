#include "DBItem.h"
#include <iostream>

namespace War3Source {
	DBItem::DBItem(unsigned int id, unsigned int characterId, const char *className, const char *data) {
		this->id = id;
		this->characterId = characterId;
		strcpy_s(this->className, sizeof(this->className), className);
		strcpy_s(this->data, sizeof(this->data), data);
	}

	DBItem::~DBItem() {
	}

	void DBItem::Destroy() {
		delete this;
	}

	unsigned int DBItem::GetID() {
		return this->id;
	}

	unsigned int DBItem::GetCharacterID() {
		return this->characterId;
	}

	const char *DBItem::GetClass() {
		return this->className;
	}

	const char *DBItem::GetData() {
		return this->data;
	}
}