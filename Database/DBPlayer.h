#ifndef __war3source_databaseplayer_h__
#define __war3source_databaseplayer_h__

#include "IDBPlayer.h"

namespace War3Source {
	class DBPlayer : public IDBPlayer {
	public:
		DBPlayer(unsigned int id, const char *steamID, unsigned int activeCharacterID);
		~DBPlayer();

		void Destroy();
		unsigned int GetID();
		const char *GetSteamID();
		unsigned int GetActiveCharacterID();

	private:
		unsigned int id;
		char steamID[64];
		unsigned int activeCharacterID;
	};
}

#endif