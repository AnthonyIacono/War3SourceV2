#ifndef __war3source_PLItemCallback_h__
#define __war3source_PLItemCallback_h__

#include "IQueryCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDBCharacter.h"
#include "IDBPlayer.h"
#include "IList.h"

namespace War3Source {
	class PLItemCallback : public IQueryCallback {
	public:
		PLItemCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer, IList<IDBCharacter*> *DBCharacters);
		~PLItemCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDBPlayer *databasePlayer;
		IList<IDBCharacter*> *DBCharacters;
	};
}

#endif