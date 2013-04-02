#ifndef __war3source_connectoperation_h__
#define __war3source_connectoperation_h__

#include "extension.h"
#include "IConnectCallback.h"
#include <IShareSys.h>
#include <IDBDriver.h>

namespace War3Source {
	class ConnectOperation : public IDBThreadOperation {
	public:
		ConnectOperation(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *dbInfo, IConnectCallback *callback);

		SourceMod::IdentityToken_t *GetOwner();
		SourceMod::IDBDriver *GetDriver();
		void RunThreadPart();
		void CancelThinkPart();
		void RunThinkPart();
		void Destroy();

	private:
		SourceMod::IDBDriver *dbDriver;
		const SourceMod::DatabaseInfo *dbInfo;
		IConnectCallback *callback;

	private:
		SourceMod::IDatabase *database;
		char connectionError[1024];
	};
}

#endif