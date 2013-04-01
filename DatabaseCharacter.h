#ifndef __war3source_databasecharacter_h__
#define __war3source_databasecharacter_h__

#include "IDatabaseCharacter.h"

namespace War3Source {
	class DatabaseCharacter : public IDatabaseCharacter {
	public:
		DatabaseCharacter(unsigned int id, unsigned int playerID, const char *className, const char *name, unsigned int level, unsigned int xp);
		~DatabaseCharacter();

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