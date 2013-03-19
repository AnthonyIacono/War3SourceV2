#ifndef __war3source_iplayerloader_h__
#define __war3source_iplayerloader_h__

#include "IPlayerLoaderCallback.h"

namespace War3Source {
	class IPlayerLoader {
	public:
		virtual void LoadPlayer() = 0;
		virtual IPlayerLoaderCallback *GetCallback() = 0;
		virtual const char *GetSteamID() = 0;
	};
}

#endif