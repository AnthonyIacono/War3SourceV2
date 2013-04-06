#include <sourcemod_version.h>
#include "Extension.h"
#include "ConnectOperation.h"
#include "ConnectCallback.h"
#include "Clientlistener.h"
#include "Globals.h"
#include "ClientCommandListener.h"
#include <engine\ivdebugoverlay.h>
#include "CompatWrappers.h"
#include "SayCommandListener.h"

using namespace SourceHook;

SMEXT_LINK(&g_War3SourceExtension);

IVDebugOverlay *debugOverlay = NULL;

#if SOURCE_ENGINE >= SE_ORANGEBOX
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, edict_t *, const CCommand &);
#else
SH_DECL_HOOK1_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, edict_t *);
#endif


#if SOURCE_ENGINE >= SE_ORANGEBOX
	SH_DECL_HOOK1_void(ConCommand, Dispatch, SH_NOATTRIB, false, const CCommand &);
#else
	SH_DECL_HOOK0_void(ConCommand, Dispatch, SH_NOATTRIB, false);
#endif

SH_DECL_HOOK1_void(IServerGameClients, SetCommandClient, SH_NOATTRIB, false, int);

/* :HACKHACK: We can't SH_DECL here because ConCmdManager.cpp does.
 * While the OB build only runs on MM:S 1.6.0+ (SH 5+), the older one 
 * can technically be compiled against any MM:S version after 1.4.2.
 */
#if SOURCE_ENGINE >= SE_ORANGEBOX
extern bool __SourceHook_FHRemoveConCommandDispatch(void *, bool, class fastdelegate::FastDelegate1<const CCommand &, void>);
extern int __SourceHook_FHAddConCommandDispatch(void *, ISourceHook::AddHookMode, bool, class fastdelegate::FastDelegate1<const CCommand &, void>);
#else
extern bool __SourceHook_FHRemoveConCommandDispatch(void *, bool, class fastdelegate::FastDelegate0<void>);
#if SH_IMPL_VERSION >= 5
extern int __SourceHook_FHAddConCommandDispatch(void *, ISourceHook::AddHookMode, bool, class fastdelegate::FastDelegate0<void>);
#elif SH_IMPL_VERSION == 4
extern int __SourceHook_FHAddConCommandDispatch(void *, bool, class fastdelegate::FastDelegate0<void>);
#elif SH_IMPL_VERSION == 3
extern bool __SourceHook_FHAddConCommandDispatch(void *, bool, class fastdelegate::FastDelegate0<void>);
#endif //SH_IMPL_VERSION
#endif //SE_ORANGEBOX

namespace War3Source {
	bool Extension::SDK_OnLoad(char *error, size_t err_max, bool late) {
		const DatabaseInfo *dbInfo = dbi->FindDatabaseConf("war3source");

		if(NULL == dbInfo) {
			dbInfo = dbi->FindDatabaseConf("default");

			if(dbInfo == NULL) {
				StrCopy(error, err_max, "Unable to find database configuration for war3source or default.");
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
			StrCopy(error, err_max, "Unable to load database driver.");
			return false;
		}


		META_CONPRINTF("Connecting to DB...\n");

		IConnectCallback *connectCallback = new ConnectCallback();
		ConnectOperation *connectOperation = new ConnectOperation(dbDriver, dbInfo, connectCallback);
	
		dbi->AddToThreadQueue(connectOperation, PrioQueue_Normal);

		return true;
	}

	void Extension::SDK_OnUnload() {
		ConCommand *sayCommand = FindCommand("say");
		ConCommand *sayTeamCommand = FindCommand("say_team");

		if(sayCommand) {
			SH_REMOVE_HOOK_MEMFUNC(ConCommand, Dispatch, sayCommand, g_SayCommandListener, &ISayCommandListener::OnSayCommand, false);
		}
		
		if(sayTeamCommand) {
			SH_REMOVE_HOOK_MEMFUNC(ConCommand, Dispatch, sayTeamCommand, g_SayCommandListener, &ISayCommandListener::OnSayCommand, false);
		}

		SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, g_ServerGameClients, g_ClientCommandListener, &IClientCommandListener::OnClientCommand, false);
	}

	const char *Extension::GetExtensionVerString() {
		return SMEXT_CONF_VERSION;
	}

	const char *Extension::GetExtensionDateString() {
		return SM_BUILD_TIMESTAMP;
	}

	bool Extension::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late) {
		GET_V_IFACE_CURRENT(GetEngineFactory, g_CVar,
			ICvar, CVAR_INTERFACE_VERSION);

		GET_V_IFACE_ANY(GetServerFactory, g_ServerGameClients,
			IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);

		if(g_ServerGameClients == NULL) {
			StrFormat(error, maxlen, "%s", "WAR3 FATAL ERROR: Unable to find IServerGameClients\n");
			return false;
		}

		if(g_CVar == NULL) {
			StrFormat(error, maxlen, "%s", "WAR3 FATAL ERROR: Unable to find ICvar\n");
			return false;
		}

		icvar = g_CVar;
		g_Globals = ismm->GetCGlobals();
		gpGlobals = g_Globals;

		ConCommand *sayCommand = FindCommand("say");
		ConCommand *sayTeamCommand = FindCommand("say_team");

		g_SayCommandListener = new SayCommandListener();

		if(sayCommand) {
			SH_ADD_HOOK_MEMFUNC(ConCommand, Dispatch, sayCommand, g_SayCommandListener, &ISayCommandListener::OnSayCommand, false);
		}
		
		if(sayTeamCommand) {
			SH_ADD_HOOK_MEMFUNC(ConCommand, Dispatch, sayTeamCommand, g_SayCommandListener, &ISayCommandListener::OnSayCommand, false);
		}

		return true;
	}

	bool Extension::QueryRunning(char *error, size_t maxlength) {
		return true;
	}

	void Extension::SDK_OnAllLoaded() {
		g_ClientCommandListener = new ClientCommandListener();

		SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, g_ServerGameClients, g_ClientCommandListener, &IClientCommandListener::OnClientCommand, false);
		SH_ADD_HOOK_MEMFUNC(IServerGameClients, SetCommandClient, g_ServerGameClients, g_ClientCommandListener, &IClientCommandListener::OnSetCommandClient, false);
	}
}