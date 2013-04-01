#ifndef __war3source_playerbinder_h__
#define __war3source_playerbinder_h__

#include "IPlayerBinder.h"
#include "IList.h"
#include "IDatabasePlayer.h"
#include "IDatabaseItem.h"
#include "IDatabaseSkill.h"
#include "IDatabaseCharacter.h"
#include "IDatabaseQuest.h"

namespace War3Source {
	class PlayerBinder : public IPlayerBinder {
	public:
		PlayerBinder(IDatabasePlayer *databasePlayer, IList<IDatabaseCharacter*> *databaseCharacters,
			IList<IDatabaseItem*> *databaseItems, IList<IDatabaseSkill*> *databaseSkills,
			IList<IDatabaseQuest*> *databaseQuests);
		~PlayerBinder();

		void Destroy();
		IPlayer *BindPlayerData();

	private:
		IDatabasePlayer *databasePlayer;
		IList<IDatabaseItem*> *databaseItems;
		IList<IDatabaseCharacter*> *databaseCharacters;
		IList<IDatabaseSkill*> *databaseSkills;
		IList<IDatabaseQuest*> *databaseQuests;
	};
}

#endif