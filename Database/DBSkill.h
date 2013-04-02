#ifndef __war3source_databaseskill_h__
#define __war3source_databaseskill_h__

#include "IDBSkill.h"

namespace War3Source {
	class DBSkill : public IDBSkill {
	public:
		DBSkill(unsigned int id, unsigned int characterId, const char *className, unsigned int level);
		~DBSkill();

		void Destroy();
		unsigned int GetID();
		unsigned int GetCharacterID();
		const char *GetClass();
		unsigned int GetLevel();

	private:
		unsigned int id;
		unsigned int characterId;
		char className[64];
		unsigned int level;
	};
}

#endif