#ifndef __war3source_databasequest_h__
#define __war3source_databasequest_h__

#include "IDatabaseQuest.h"

namespace War3Source {
	class DatabaseQuest : public IDatabaseQuest {
	public:
		DatabaseSkill(unsigned int id, unsigned int characterId, const char *className, const char *data);
		~DatabaseSkill();

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