#ifndef __war3source_querydbthreadoperation_h__
#define __war3source_querydbthreadoperation_h__

#include "extension.h"
#include "IQueryDBThreadOperationCallback.h"
#include <IShareSys.h>

namespace War3Source {
	class QueryDBThreadOperation : public IDBThreadOperation {
	public:
		QueryDBThreadOperation(const char *query, IQueryDBThreadOperationCallback *callback);

		SourceMod::IdentityToken_t *GetOwner();
		SourceMod::IDBDriver *GetDriver();
		void RunThreadPart();
		void CancelThinkPart();
		void RunThinkPart();
		void Destroy();

	private:
		char query[4096];
		IQueryDBThreadOperationCallback *callback;

	private:
		char error[4096];
		int errorCode;
		SourceMod::IQuery *results;
	};
}

#endif