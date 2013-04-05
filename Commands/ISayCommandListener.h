#ifndef __war3source_isaycommandlistener_h__
#define __war3source_isaycommandlistener_h__

#include "HL2SDK.h"
#include "CompatWrappers.h"

namespace War3Source {
	/**
	 * Represents a say command listener (for both say and say_team)
	 */
	class ISayCommandListener {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Called when a say command is caught.
		 */
		#if SOURCE_ENGINE >= SE_ORANGEBOX
		virtual void OnSayCommand(const CCommand &command) = 0;
		#else
		virtual void OnSayCommand() = 0;
		#endif
	};
}

#endif