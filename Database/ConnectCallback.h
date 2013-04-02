#ifndef __war3source_tconnectcallback_h__
#define __war3source_tconnectcallback_h__

#include "IConnectCallback.h"
#include <IDBDriver.h>

namespace War3Source {
	class ConnectCallback : public IConnectCallback {
	public:
		ConnectCallback();
		~ConnectCallback();

		void OnCancel(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo);
		void OnSuccess(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, SourceMod::IDatabase *database);
		void OnError(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, const char *error);
	};
}

#endif