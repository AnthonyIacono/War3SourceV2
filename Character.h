#ifndef __war3source_character_h__
#define __war3source_character_h__

#include "ICharacter.h"

namespace War3Source {
	class Character : public ICharacter {
	public:
		Character(const char *name, const char *className, unsigned int level, unsigned int xp, IList<ISkill*> *skills, IList<IItem*> *items, IList<IQuest*> *quests);
		~Character();

		void Destroy();
		const char *GetName();
		const char *GetClass();
		unsigned int GetLevel();
		unsigned int GetXP();
		IList<ISkill*> *GetSkillList();
		IList<IItem*> *GetItemList();
		IList<IQuest*> *GetQuestList();

	private:
		char name[64];
		char className[64];
		unsigned int level;
		unsigned int xp;
		IList<ISkill*> *skills;
		IList<IItem*> *items;
		IList<IQuest*> *quests;
	};
}

#endif