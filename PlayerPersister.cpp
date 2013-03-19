#include "PlayerPersister.h"

using namespace SourceMod;
#include "sdk/smsdk_ext.h"

namespace War3Source {
	PlayerPersister::PlayerPersister(IPlayer *player, IDatabase *database, IDBDriver *dbDriver, IPlayerPersisterCallback *callback) {
		this->player = player;
		this->database = database;
		this->dbDriver = dbDriver;
		this->callback = callback;
	}

	void PlayerPersister::Persist() {

	}
}