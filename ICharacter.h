#ifndef __war3source_icharacter_h__
#define __war3source_icharacter_h__

#include "IList.h"
#include "ISkill.h"

namespace War3Source {
	class ICharacter {
	public:
		virtual const char *GetName() = 0;
		virtual int GetLevel() = 0;
		virtual int GetXP() = 0;
		virtual IList<ISkill*> *GetSkillList() = 0;
	};
}

#endif