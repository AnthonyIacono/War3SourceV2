#ifndef __war3source_playerloadercallback_h__
#define __war3source_playerloadercallback_h__

#include "IPlayerLoaderCallback.h"

namespace War3Source {
	class PlayerLoaderCallback : public IPlayerLoaderCallback {
	public:
		PlayerLoaderCallback();
		~PlayerLoaderCallback();

		void OnNotFound(const char *steamID);
		void OnLoaded(const char *steamID, IPlayer *player);
	};
}
#endif