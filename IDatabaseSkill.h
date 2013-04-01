#ifndef __war3source_idatabaseskill_h__
#define __war3source_idatabaseskill_h__

namespace War3Source {
	/**
	 * A skill loaded from the database.
	 */
	class IDatabaseSkill {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;
		
		/**
		 * Retrieve the ID column.
		 */
		virtual unsigned int GetID() = 0;

		/**
		 * Retrieve the character ID column.
		 */
		virtual unsigned int GetCharacterID() = 0;

		/**
		 * Retrieve the class column.
		 */
		virtual const char *GetClass() = 0;

		/**
		 * Retrieve the level column.
		 */
		virtual unsigned int GetLevel() = 0;
	};
}

#endif