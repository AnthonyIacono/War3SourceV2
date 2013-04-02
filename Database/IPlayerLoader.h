#ifndef __war3source_iplayerloader_h__
#define __war3source_iplayerloader_h__

#include "IPlayerLoaderCallback.h"

namespace War3Source {
	/**
	 * Represents a player loader.
	 */
	class IPlayerLoader {
	public:
		/**
		 * Load player from database.
		 */
		virtual void LoadPlayer() = 0;

		/**
		 * Retrieve the player loader's callback.
		 */
		virtual IPlayerLoaderCallback *GetCallback() = 0;

		/**
		 * Retrieve the steam ID for the player being loaded.
		 */
		virtual const char *GetSteamID() = 0;
	};
}

#endif