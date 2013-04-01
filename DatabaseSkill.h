#ifndef __war3source_databaseskill_h__
#define __war3source_databaseskill_h__

#include "IDatabaseSkill.h"

namespace War3Source {
	class DatabaseSkill : public IDatabaseSkill {
	public:
		DatabaseSkill(unsigned int id, unsigned int characterId, const char *className, unsigned int level);
		~DatabaseSkill();

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