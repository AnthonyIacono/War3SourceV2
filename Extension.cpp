#include <sourcemod_version.h>
#include "Extension.h"
#include "ConnectDBThreadOperation.h"
#include "ConnectDBThreadOperationCallback.h"
#include "Clientlistener.h"
#include "Globals.h"
#include <engine\ivdebugoverlay.h>
using namespace SourceHook;

SMEXT_LINK(&g_War3SourceExtension);

IVDebugOverlay *debugOverlay = NULL;

namespace War3Source {
	bool Extension::SDK_OnLoad(char *error, size_t err_max, bool late) {
		const DatabaseInfo *dbInfo = dbi->FindDatabaseConf("war3source");

		if(NULL == dbInfo) {
			dbInfo = dbi->FindDatabaseConf("default");

			if(dbInfo == NULL) {
				strcpy_s(error, err_max, "Unable to find database configuration for war3source or default.");
				return false;
			}
		}

		IDBDriver *dbDriver = NULL;

		if(dbInfo->driver[0] == '\0') {
			dbDriver = dbi->GetDefaultDriver();
		}
		else {
			dbDriver = dbi->FindOrLoadDriver(dbInfo->driver);
		}

		if(NULL == dbDriver) {
			strcpy_s(error, err_max, "Unable to load database driver.");
			return false;
		}


		META_CONPRINTF("Connecting to DB...\n");

		ConnectDBThreadOperationCallback *connectDBThreadOperationCallback = new ConnectDBThreadOperationCallback();
		ConnectDBThreadOperation *connectDBThreadOperation = new ConnectDBThreadOperation(dbDriver, dbInfo, connectDBThreadOperationCallback);
	
		dbi->AddToThreadQueue(connectDBThreadOperation, PrioQueue_Normal);

		return true;
	}

	void Extension::SDK_OnUnload() {
	}

	const char *Extension::GetExtensionVerString() {
		return SMEXT_CONF_VERSION;
	}

	const char *Extension::GetExtensionDateString() {
		return SM_BUILD_TIMESTAMP;
	}

	bool Extension::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlength, bool late) {
		return true;
	}

	bool Extension::QueryRunning(char *error, size_t maxlength) {
		return true;
	}
}