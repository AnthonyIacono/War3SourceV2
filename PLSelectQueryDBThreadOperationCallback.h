#ifndef __war3source_plselectquerydbthreadoperationcallback_h__
#define __war3source_plselectquerydbthreadoperationcallback_h__

#include "IQueryDBThreadOperationCallback.h"
#include <IDBDriver.h>
#include "IPlayerLoader.h"

namespace War3Source {
	class PLSelectQueryDBThreadOperationCallback : public IQueryDBThreadOperationCallback {
	public:
		PLSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader);
		~PLSelectQueryDBThreadOperationCallback();

		void OnError(const char *query, const char *error, int errorCode);
		void OnSuccess(const char *query, SourceMod::IQuery *results);
		void OnCancel(const char *query);

	private:
		IPlayerLoader *playerLoader;
		char steamID[64];
	};
}

#endif