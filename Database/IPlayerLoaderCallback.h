#ifndef __war3source_iplayerloadercallback_h__
#define __war3source_iplayerloadercallback_h__

#include "IPlayer.h"

namespace War3Source {
	/**
	 * Represents a player loader callback.
	 */
	class IPlayerLoaderCallback {
	public:
		/**
		 * Called when the player is not found in the database.
		 */
		virtual void OnNotFound(const char *steamID) = 0;

		/**
		 * Called when a player is loaded from the database.
		 */
		virtual void OnLoaded(const char *steamID, IPlayer *player) = 0;
	};
}

#endif