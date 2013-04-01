#ifndef __war3source_plitemselectquerydbthreadoperationcallback_h__
#define __war3source_plitemselectquerydbthreadoperationcallback_h__

#include "IQueryDBThreadOperationCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDatabaseCharacter.h"
#include "IDatabasePlayer.h"
#include "IList.h"

namespace War3Source {
	class PLItemSelectQueryDBThreadOperationCallback : public IQueryDBThreadOperationCallback {
	public:
		PLItemSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader, IDatabasePlayer *databasePlayer, IList<IDatabaseCharacter*> *databaseCharacters);
		~PLItemSelectQueryDBThreadOperationCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDatabasePlayer *databasePlayer;
		IList<IDatabaseCharacter*> *databaseCharacters;
	};
}

#endif