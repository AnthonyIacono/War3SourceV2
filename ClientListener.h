#ifndef __war3source_clientlistener_h__
#define __war3source_clientlistener_h__

#include <IPlayerHelpers.h>

namespace War3Source {
	class ClientListener : public SourceMod::IClientListener {
	public:
		ClientListener();
		~ClientListener();

		void OnClientPutInServer(int clientIndex);
		void OnClientDisconnecting(int clientIndex);
		void OnClientAuthorized(int clientIndex, const char *authString);
		void OnServerActivated(int maxClients);
	};
}

#endif