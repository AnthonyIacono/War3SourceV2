#ifndef __war3souce_iplayerbinder_h__
#define __war3souce_iplayerbinder_h__

#include "IPlayer.h"

namespace War3Source {
	/**
	 * Binds data loaded from the MySQL/SQLite DB into an IPlayer.
	 */
	class IPlayerBinder {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;
		
		/**
		 * Bind the player data and return an IPlayer.
		 */
		virtual IPlayer *BindPlayerData() = 0;
	};
}

#endif