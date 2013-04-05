#ifndef __war3source_clientcommandlistener_h__
#define __war3source_clientcommandlistener_h__

#include "IClientCommandListener.h"

namespace War3Source {
	class ClientCommandListener : public IClientCommandListener {
	public:
		ClientCommandListener();
		~ClientCommandListener();

		void Destroy();

		#if SOURCE_ENGINE >= SE_ORANGEBOX
		void OnClientCommand(edict_t *edict, const CCommand &command);
		#else
		void OnClientCommand(edict_t *edict);
		#endif
	};
}

#endif