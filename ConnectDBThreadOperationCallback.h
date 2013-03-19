#ifndef __war3source_connectdbthreadoperationcallback_h__
#define __war3source_connectdbthreadoperationcallback_h__

#include "IConnectDBThreadOperationCallback.h"
#include <IDBDriver.h>

namespace War3Source {
	class ConnectDBThreadOperationCallback : public IConnectDBThreadOperationCallback {
	public:
		ConnectDBThreadOperationCallback();
		~ConnectDBThreadOperationCallback();

		void OnCancel(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo);
		void OnSuccess(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, SourceMod::IDatabase *database);
		void OnError(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, const char *error);
	};
}

#endif