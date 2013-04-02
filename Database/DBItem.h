#ifndef __war3source_databaseitem_h__
#define __war3source_databaseitem_h__

#include "IDBItem.h"

namespace War3Source {
	class DBItem : public IDBItem {
	public:
		DBItem(unsigned int id, unsigned int characterId, const char *className, const char *data);
		~DBItem();

		void Destroy();
		unsigned int GetID();
		unsigned int GetCharacterID();
		const char *GetClass();
		const char *GetData();

	private:
		unsigned int id;
		unsigned int characterId;
		char className[64];
		char data[4096];
	};
}

#endif