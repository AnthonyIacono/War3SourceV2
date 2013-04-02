#ifndef __war3source_queryoperation_h__
#define __war3source_queryoperation_h__

#include "extension.h"
#include "IQueryCallback.h"
#include <IShareSys.h>

namespace War3Source {
	class QueryOperation : public IDBThreadOperation {
	public:
		QueryOperation(const char *query, IQueryCallback *callback);

		SourceMod::IdentityToken_t *GetOwner();
		SourceMod::IDBDriver *GetDriver();
		void RunThreadPart();
		void CancelThinkPart();
		void RunThinkPart();
		void Destroy();

	private:
		char query[4096];
		IQueryCallback *callback;

	private:
		char error[4096];
		int errorCode;
		SourceMod::IQuery *results;
	};
}

#endif