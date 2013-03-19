#include "ConnectDBThreadOperationCallback.h"
#include "sdk/smsdk_ext.h"
#include "ClientListener.h"
#include "Globals.h"
#include "NavMeshLoader.h"
#include "INavMesh.h"
using namespace SourceMod;

namespace War3Source {
	ConnectDBThreadOperationCallback::ConnectDBThreadOperationCallback() {
	}

	ConnectDBThreadOperationCallback::~ConnectDBThreadOperationCallback() {
	}

	void ConnectDBThreadOperationCallback::OnCancel(IDBDriver *dbDriver, const DatabaseInfo *databaseInfo) {
	}

	void ConnectDBThreadOperationCallback::OnSuccess(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *databaseInfo, SourceMod::IDatabase *database) {
		g_DBDriver = dbDriver;
		g_Database = database;

		g_ClientListener = new ClientListener();
		playerhelpers->AddClientListener(g_ClientListener);

		if(g_pSM->IsMapRunning()) {
			const char *currentMap = gamehelpers->GetCurrentMap();

			char error[1024];
			NavMeshLoader *loader = new NavMeshLoader(currentMap);
			//INavMesh *mesh = loader->Load(error, sizeof(error));
			//META_CONPRINTF("Error str: %s", error);
		}
	}

	void ConnectDBThreadOperationCallback::OnError(SourceMod::IDBDriver *dbDriver, const SourceMod::DatabaseInfo *databaseInfo, const char *error) {
	}
}