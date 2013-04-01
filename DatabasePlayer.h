#ifndef __war3source_databaseplayer_h__
#define __war3source_databaseplayer_h__

#include "IDatabasePlayer.h"

namespace War3Source {
	class DatabasePlayer : public IDatabasePlayer {
	public:
		DatabasePlayer(unsigned int id, const char *steamID, unsigned int activeCharacterID);
		~DatabasePlayer();

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