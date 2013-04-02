#ifndef __war3source_IDBPlayer_h__
#define __war3source_IDBPlayer_h__

namespace War3Source {
	/**
	 * A player loaded from the database.
	 */
	class IDBPlayer {
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
		 * Retrieve the steam ID column.
		 */
		virtual const char *GetSteamID() = 0;

		/**
		 * Retrieve the active character ID column.
		 */
		virtual unsigned int GetActiveCharacterID() = 0;
	};
}

#endif