#ifndef __war3source_playerpersister_h__
#define __war3source_playerpersister_h__

#include "IPlayerPersister.h"
#include "IPlayer.h"
#include <IDBDriver.h>
#include "IPlayerPersisterCallback.h"

namespace War3Source {
	class PlayerPersister : public IPlayerPersister {
	public:
		PlayerPersister(IPlayer *player, SourceMod::IDatabase *database, SourceMod::IDBDriver *dbDriver, IPlayerPersisterCallback *callback);
		~PlayerPersister();

		void Persist();

	private:
		IPlayer *player;
		SourceMod::IDatabase *database;
		SourceMod::IDBDriver *dbDriver;
		IPlayerPersisterCallback *callback;
	};
}

#endif