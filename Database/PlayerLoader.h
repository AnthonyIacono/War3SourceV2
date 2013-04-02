#ifndef __war3source_playerloader_h__
#define __war3source_playerloader_h__

#include "IPlayerLoader.h"
#include "IPlayerLoaderCallback.h"

namespace War3Source {
	class PlayerLoader : public IPlayerLoader {
	public:
		PlayerLoader(const char *steamID, IPlayerLoaderCallback *callback);
		~PlayerLoader();

		void LoadPlayer();
		IPlayerLoaderCallback *GetCallback();
		const char *GetSteamID();

	private:
		char steamID[64];
		IPlayerLoaderCallback *callback;
	};
}

#endif