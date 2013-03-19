#ifndef __war3source_extension_h__
#define __war3source_extension_h__

#include "sdk/smsdk_ext.h"

namespace War3Source {
	class Extension : public SDKExtension {
	public:
		virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
		virtual void SDK_OnUnload();
		const char *GetExtensionVerString();
		const char *GetExtensionDateString();
		virtual bool QueryRunning(char *error, size_t maxlength);

	public:
		virtual bool SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlength, bool late);
	};
}

#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
