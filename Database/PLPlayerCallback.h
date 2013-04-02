#ifndef __war3source_plplayercallback_h__
#define __war3source_plplayercallback_h__

#include "IQueryCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"

namespace War3Source {
	class PLPlayerCallback : public IQueryCallback {
	public:
		PLPlayerCallback(IPlayerLoader *playerLoader);
		~PLPlayerCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
	};
}

#endif