#ifndef __war3source_itconnectcallback_h__
#define __war3source_itconnectcallback_h__

#include <IDBDriver.h>

namespace War3Source {
	/**
	 * Represents a database connection's callback.
	 */
	class IConnectCallback {
	public:
		/**
		 * Called when the database connection is cancelled.
		 */
		virtual void OnCancel(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo) = 0;

		/**
		 * Called when the database connection is obtained successfully.
		 */
		virtual void OnSuccess(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, SourceMod::IDatabase *database) = 0;

		/**
		 * Called when there is an error obtaining a connection to the database.
		 */
		virtual void OnError(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, const char *error) = 0;
	};
}

#endif