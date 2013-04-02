#ifndef __war3source_playerbinder_h__
#define __war3source_playerbinder_h__

#include "IPlayerBinder.h"
#include "IList.h"
#include "IDBPlayer.h"
#include "IDBItem.h"
#include "IDBSkill.h"
#include "IDBCharacter.h"
#include "IDBQuest.h"

namespace War3Source {
	class PlayerBinder : public IPlayerBinder {
	public:
		PlayerBinder(IDBPlayer *databasePlayer, IList<IDBCharacter*> *DBCharacters,
			IList<IDBItem*> *databaseItems, IList<IDBSkill*> *databaseSkills,
			IList<IDBQuest*> *databaseQuests);
		~PlayerBinder();

		void Destroy();
		IPlayer *BindPlayerData();

	private:
		IDBPlayer *databasePlayer;
		IList<IDBItem*> *databaseItems;
		IList<IDBCharacter*> *DBCharacters;
		IList<IDBSkill*> *databaseSkills;
		IList<IDBQuest*> *databaseQuests;
	};
}

#endif