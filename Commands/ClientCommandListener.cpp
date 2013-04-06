#include "ClientCommandListener.h"
#include "CompatWrappers.h"
#include "sdk\smsdk_ext.h"

namespace War3Source {
	ClientCommandListener::ClientCommandListener(int commandClient) {
		this->commandClient = commandClient;
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

	void ClientCommandListener::OnSetCommandClient(int index) {
		META_CONPRINTF("SetCommandClient() called with value %d\n", index);

		this->commandClient = index + 1; // For some reason SM had to increment one so I assume we will too.
	}

	int ClientCommandListener::GetCommandClient() {
		return this->commandClient;
	}
}