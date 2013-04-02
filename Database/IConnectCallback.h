#ifndef __war3source_itconnectcallback_h__
#define __war3source_itconnectcallback_h__

#include <IDBDriver.h>

namespace War3Source {
	class IConnectCallback {
	public:
		virtual void OnCancel(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo) = 0;
		virtual void OnSuccess(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, SourceMod::IDatabase *database) = 0;
		virtual void OnError(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, const char *error) = 0;
	};
}

#endif