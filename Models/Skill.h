#ifndef __war3source_skill_h__
#define __war3source_skill_h__

#include "ISkill.h"

namespace War3Source {
	class Skill : public ISkill {
	public:
		Skill(const char *name, const char *className, unsigned int level);
		~Skill();

		void Destroy();
		const char *GetName();
		const char *GetClass();
		int GetLevel();
	
	private:
		char name[64];
		char className[64];
		unsigned int level;
	};
}

#endif