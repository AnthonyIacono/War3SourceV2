#ifndef __war3source_iclientcommandlistener_h__
#define __war3source_iclientcommandlistener_h__

#include "HL2SDK.h"

namespace War3Source {
	/**
	 * Represents a client command listener.
	 */
	class IClientCommandListener {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Called when a client command is caught.
		 */
		#if SOURCE_ENGINE >= SE_ORANGEBOX
		virtual void OnClientCommand(edict_t *edict, const CCommand &command) = 0;
		#else
		virtual void OnClientCommand(edict_t *edict) = 0;
		#endif

		/**
		 * Called when the command client is set.
		 */
		virtual void OnSetCommandClient(int index) = 0;

		/**
		 * Retrieve the last set command client.
		 */
		virtual int GetCommandClient() = 0;
	};
}

#endif