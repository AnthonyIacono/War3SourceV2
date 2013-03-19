#include "ClientListener.h"
#include "PlayerLoader.h"
#include "PlayerLoaderCallback.h"
#include "sdk/smsdk_ext.h"
#include "NavMeshLoader.h"

namespace War3Source {
	ClientListener::ClientListener() {
	}

	ClientListener::~ClientListener() {
	}

	void ClientListener::OnClientPutInServer(int clientIndex) {
		IGamePlayer *gamePlayer = playerhelpers->GetGamePlayer(clientIndex);

		if(!gamePlayer->IsConnected() || !gamePlayer->IsAuthorized()) {
			return;
		}

		if(gamePlayer->IsFakeClient()) {
			// meep
			return;
		}

		IPlayerLoaderCallback *playerLoaderCallback = new PlayerLoaderCallback();
		IPlayerLoader *playerLoader = new PlayerLoader(gamePlayer->GetAuthString(), playerLoaderCallback);

		playerLoader->LoadPlayer();
	}

	void ClientListener::OnClientDisconnecting(int clientIndex) {

	}

	void ClientListener::OnClientAuthorized(int clientIndex, const char *authString) {
		IGamePlayer *gamePlayer = playerhelpers->GetGamePlayer(clientIndex);

		if(!gamePlayer->IsConnected() || !gamePlayer->IsInGame()) {
			return;
		}

		if(gamePlayer->IsFakeClient()) {
			// meep
			return;
		}

		META_CONPRINTF("Load time :)\n");
	}

	void ClientListener::OnServerActivated(int maxClients) {
		const char *currentMap = gamehelpers->GetCurrentMap();

		META_CONPRINTF("Activated: %d %s\n", maxClients, currentMap);

		NavMeshLoader *loader = new NavMeshLoader(currentMap);

		char error[1024];
		INavMesh *mesh = loader->Load(error, sizeof(error));
	}
}