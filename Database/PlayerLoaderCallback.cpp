#include "PlayerLoaderCallback.h"
#include "sdk/smsdk_ext.h"

namespace War3Source {
	PlayerLoaderCallback::PlayerLoaderCallback() {
	}

	PlayerLoaderCallback::~PlayerLoaderCallback() {
	}


	void PlayerLoaderCallback::OnNotFound(const char *steamID) {
		
	}

	void PlayerLoaderCallback::OnLoaded(const char *steamID, IPlayer *player) {
		META_CONPRINTF("Player loaded from database.\n");
	}
}