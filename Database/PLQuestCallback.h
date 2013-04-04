#ifndef __war3source_plquestcallback_h__
#define __war3source_plquestcallback_h__

#include "IQueryCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDBCharacter.h"
#include "IDBPlayer.h"
#include "IDBItem.h"
#include "IDBSkill.h"
#include "IList.h"

namespace War3Source {
	class PLQuestCallback : public IQueryCallback {
	public:
		PLQuestCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer,
			IList<IDBCharacter*> *databaseCharacters, IList<IDBItem*> *databaseItems,
			IList<IDBSkill*> *databaseSkills);
		~PLQuestCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDBPlayer *databasePlayer;
		IList<IDBCharacter*> *databaseCharacters;
		IList<IDBItem*> *databaseItems;
		IList<IDBSkill*> *databaseSkills;
	};
}

#endif