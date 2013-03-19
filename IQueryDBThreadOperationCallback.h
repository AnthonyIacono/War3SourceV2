#ifndef __war3source_iquerydbthreadoperationcallback_h__
#define __war3source_iquerydbthreadoperationcallback_h__

#include <IDBDriver.h>

namespace War3Source {
	class IQueryDBThreadOperationCallback {
	public:
		virtual void OnError(const char *query, const char *error, int errorCode) = 0;
		virtual void OnSuccess(const char *query, SourceMod::IQuery *results) = 0;
		virtual void OnCancel(const char *query) = 0;
	};
}

#endif