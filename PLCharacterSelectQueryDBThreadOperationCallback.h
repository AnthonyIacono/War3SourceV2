#ifndef __war3source_plcharacterselectquerydbthreadoperationcallback_h__
#define __war3source_plcharacterselectquerydbthreadoperationcallback_h__

#include "IQueryDBThreadOperationCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDatabasePlayer.h"

namespace War3Source {
	class PLCharacterSelectQueryDBThreadOperationCallback : public IQueryDBThreadOperationCallback {
	public:
		PLCharacterSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader, IDatabasePlayer *databasePlayer);
		~PLCharacterSelectQueryDBThreadOperationCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDatabasePlayer *databasePlayer;
	};
}

#endif