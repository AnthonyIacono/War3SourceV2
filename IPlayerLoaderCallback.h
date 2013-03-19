#ifndef __war3source_iplayerloadercallback_h__
#define __war3source_iplayerloadercallback_h__

#include "IPlayer.h"

namespace War3Source {
	class IPlayerLoaderCallback {
	public:
		virtual void OnNotFound(const char *steamID) = 0;
		virtual void OnLoaded(const char *steamID, IPlayer *player) = 0;
	};
}

#endif