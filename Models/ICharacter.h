#ifndef __war3source_icharacter_h__
#define __war3source_icharacter_h__

#include "IList.h"
#include "ISkill.h"
#include "IItem.h"
#include "IQuest.h"

namespace War3Source {
	/**
	 * Represents a player's character.
	 */
	class ICharacter {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the name of the character.
		 */
		virtual const char *GetName() = 0;

		/**
		 * Retrieve the class of the character.
		 */
		virtual const char *GetClass() = 0;

		/**
		 * Retrieve the level of the character.
		 */
		virtual unsigned int GetLevel() = 0;

		/**
		 * Retrieve the XP value of the character.
		 */
		virtual unsigned int GetXP() = 0;

		/**
		 * Retrieve the list of ISkill instances.
		 */
		virtual IList<ISkill*> *GetSkillList() = 0;

		/**
		 * Retrieve the list of IItem instances.
		 */
		virtual IList<IItem*> *GetItemList() = 0;

		/**
		 * Retrieve the list of IQuest instances.
		 */
		virtual IList<IQuest*> *GetQuestList() = 0;
	};
}

#endif