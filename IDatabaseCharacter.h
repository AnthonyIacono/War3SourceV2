#ifndef __war3source_idatabasecharacter_h__
#define __war3source_idatabasecharacter_h__

namespace War3Source {
	/**
	 * A character loaded from the database.
	 */
	class IDatabaseCharacter {
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
		 * Retrieve the player ID column.
		 */
		virtual unsigned int GetPlayerID() = 0;

		/**
		 * Retrieve the class column.
		 */
		virtual const char *GetClass() = 0;

		/**
		 * Retrieve the name column.
		 */
		virtual const char *GetName() = 0;

		/**
		 * Retrieve the level column.
		 */
		virtual unsigned int GetLevel() = 0;

		/**
		 * Retrieve the XP column.
		 */
		virtual unsigned int GetXP() = 0;
	};
}

#endif