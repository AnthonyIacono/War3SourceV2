#ifndef __war3source_iclient_h__
#define __war3source_iclient_h__

#include <IPlayerHelpers.h>
#include "IPlayer.h"
#include "HL2SDK.h"

namespace War3Source {
	/**
	 * Represents a connected client.
	 */
	class IClient {
	public:
		virtual IPlayer *GetPlayer() = 0;
		virtual int GetEntityIndex() = 0;
		virtual int GetUserId() = 0;
		virtual CBaseEntity *GetBaseEntity() = 0;
		virtual CBasePlayer *GetBasePlayer() = 0;
		virtual SourceMod::IGamePlayer *GetGamePlayer() = 0;
	};
}

#endif