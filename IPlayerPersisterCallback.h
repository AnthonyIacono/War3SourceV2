#ifndef __war3source_iplayerpersistercallback_h__
#define __war3source_iplayerpersistercallback_h__

#include "IPlayer.h"

namespace War3Source {
	class IPlayerPersisterCallback {
	public:
		virtual void OnSuccess(IPlayer *player) = 0;
		virtual void OnError(IPlayer *player, const char *error) = 0;
	};
}

#endif