#include "ClientCommandListener.h"
#include "CompatWrappers.h"
#include "sdk\smsdk_ext.h"

namespace War3Source {
	ClientCommandListener::ClientCommandListener() {
	}

	ClientCommandListener::~ClientCommandListener() {
	}

	void ClientCommandListener::Destroy() {
	}

	#if SOURCE_ENGINE >= SE_ORANGEBOX
	void ClientCommandListener::OnClientCommand(edict_t *edict, const CCommand &command) {
	#else
	void ClientCommandListener::OnClientCommand(edict_t *edict) {
		CCommand command;
	#endif
		META_CONPRINTF("The argument count is: %d\n", command.ArgC());
		RETURN_META(MRES_IGNORED);
	}
}