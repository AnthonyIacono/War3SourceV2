#ifndef __war3source_PLCharacterCallback_h__
#define __war3source_PLCharacterCallback_h__

#include "IQueryCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"
#include "IDBPlayer.h"

namespace War3Source {
	class PLCharacterCallback : public IQueryCallback {
	public:
		PLCharacterCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer);
		~PLCharacterCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		IDBPlayer *databasePlayer;
	};
}

#endif