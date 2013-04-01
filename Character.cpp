#include "Character.h"
#include <iostream>

namespace War3Source {
	Character::Character(const char *name, const char *className, unsigned int level, unsigned int xp, IList<ISkill*> *skills, IList<IItem*> *items, IList<IQuest*> *quests) {
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->className, sizeof(this->className), className);
		this->level = level;
		this->xp = xp;
		this->skills = skills;
		this->items = items;
		this->quests = quests;
	}

	Character::~Character() {
	}

	void Character::Destroy() {
		delete this;
	}

	const char *Character::GetName() {
		return this->name;
	}

	const char *Character::GetClass() {
		return this->className;
	}

	unsigned int Character::GetLevel() {
		return this->level;
	}

	unsigned int Character::GetXP() {
		return this->xp;
	}

	IList<ISkill*> *Character::GetSkillList() {
		return this->skills;
	}

	IList<IItem*> *Character::GetItemList() {
		return this->items;
	}

	IList<IQuest*> *Character::GetQuestList() {
		return this->quests;
	}
}