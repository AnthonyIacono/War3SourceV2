#ifndef __war3source_plskillselectQueryOperationcallback_h__
#define __war3source_plskillselectQueryOperationcallback_h__

#include "IQueryCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDBCharacter.h"
#include "IDBPlayer.h"
#include "IDBItem.h"
#include "IList.h"

namespace War3Source {
	class PLSkillCallback : public IQueryCallback {
	public:
		PLSkillCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer, IList<IDBCharacter*> *DBCharacters, IList<IDBItem*> *databaseItems);
		~PLSkillCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDBPlayer *databasePlayer;
		IList<IDBCharacter*> *DBCharacters;
		IList<IDBItem*> *databaseItems;
	};
}

#endif