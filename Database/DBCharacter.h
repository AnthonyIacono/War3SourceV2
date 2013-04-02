#ifndef __war3source_DBCharacter_h__
#define __war3source_DBCharacter_h__

#include "IDBCharacter.h"

namespace War3Source {
	class DBCharacter : public IDBCharacter {
	public:
		DBCharacter(unsigned int id, unsigned int playerID, const char *className, const char *name, unsigned int level, unsigned int xp);
		~DBCharacter();

		void Destroy();
		unsigned int GetID();
		unsigned int GetPlayerID();
		const char *GetClass();
		const char *GetName();
		unsigned int GetLevel();
		unsigned int GetXP();

	private:
		unsigned int id;
		unsigned int playerID;
		char className[64];
		char name[64];
		unsigned int level;
		unsigned int xp;
	};
}

#endif