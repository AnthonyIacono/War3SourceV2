#include "DatabaseItem.h"
#include <iostream>

namespace War3Source {
	DatabaseItem::DatabaseItem(unsigned int id, unsigned int characterId, const char *className, const char *data) {
		this->id = id;
		this->characterId = characterId;
		strcpy_s(this->className, sizeof(this->className), className);
		strcpy_s(this->data, sizeof(this->data), data);
	}

	DatabaseItem::~DatabaseItem() {
	}

	void DatabaseItem::Destroy() {
		delete this;
	}

	unsigned int DatabaseItem::GetID() {
		return this->id;
	}

	unsigned int DatabaseItem::GetCharacterID() {
		return this->characterId;
	}

	const char *DatabaseItem::GetClass() {
		return this->className;
	}

	const char *DatabaseItem::GetData() {
		return this->data;
	}
}