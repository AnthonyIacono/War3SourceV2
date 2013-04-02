#ifndef __war3source_iquerycallback_h__
#define __war3source_iquerycallback_h__

#include <IDBDriver.h>

namespace War3Source {
	/**
	 * Represents a database query callback.
	 */
	class IQueryCallback {
	public:
		/**
		 * Called when there is an error performing the query.
		 */
		virtual void OnError(const char *query, const char *error, int errorCode) = 0;

		/**
		 * Called when the query is performed succesfully.
		 */
		virtual void OnSuccess(const char *query, SourceMod::IQuery *results) = 0;

		/**
		 * Called when the query is cancelled premature.
		 */
		virtual void OnCancel(const char *query) = 0;
	};
}

#endif