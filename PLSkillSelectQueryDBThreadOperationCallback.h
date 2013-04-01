#ifndef __war3source_plskillselectquerydbthreadoperationcallback_h__
#define __war3source_plskillselectquerydbthreadoperationcallback_h__

#include "IQueryDBThreadOperationCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDatabaseCharacter.h"
#include "IDatabasePlayer.h"
#include "IDatabaseItem.h"
#include "IList.h"

namespace War3Source {
	class PLSkillSelectQueryDBThreadOperationCallback : public IQueryDBThreadOperationCallback {
	public:
		PLSkillSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader, IDatabasePlayer *databasePlayer, IList<IDatabaseCharacter*> *databaseCharacters, IList<IDatabaseItem*> *databaseItems);
		~PLSkillSelectQueryDBThreadOperationCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDatabasePlayer *databasePlayer;
		IList<IDatabaseCharacter*> *databaseCharacters;
		IList<IDatabaseItem*> *databaseItems;
	};
}

#endif