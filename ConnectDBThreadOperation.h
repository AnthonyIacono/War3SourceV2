#ifndef __war3source_connectdbthreadoperation_h__
#define __war3source_connectdbthreadoperation_h__

#include "extension.h"
#include "IConnectDBThreadOperationCallback.h"
#include <IShareSys.h>
#include <IDBDriver.h>

namespace War3Source {
	class ConnectDBThreadOperation : public IDBThreadOperation {
	public:
		ConnectDBThreadOperation(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, IConnectDBThreadOperationCallback *callback);

		SourceMod::IdentityToken_t *GetOwner();
		SourceMod::IDBDriver *GetDriver();
		void RunThreadPart();
		void CancelThinkPart();
		void RunThinkPart();
		void Destroy();

	private:
		SourceMod::IDBDriver *dbDriver;
		const SourceMod::DatabaseInfo *dbInfo;
		IConnectDBThreadOperationCallback *callback;

	private:
		SourceMod::IDatabase *database;
		char connectionError[1024];
	};
}

#endif