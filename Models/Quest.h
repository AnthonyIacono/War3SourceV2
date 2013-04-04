#ifndef __war3source_quest_h__
#define __war3source_quest_h__

#include "IQuest.h"
#include <sh_string.h>
#include "IMap.h"

namespace War3Source {
	class Quest : public IQuest {
	public:
		Quest(const char *name, const char *className, IMap<SourceHook::String> *properties);
		~Quest();

		void Destroy();
		const char *GetName();
		const char *GetClass();
		unsigned int GetPropUnsignedInt(const char *key, unsigned int defaultValue, bool *propExists);
		int GetPropInt(const char *key, int defaultValue, bool *propExists);
		float GetPropFloat(const char *key, float defaultValue, bool *propExists);
		SourceHook::String GetPropString(const char *key, SourceHook::String defaultValue, bool *propExists);
		void SetPropUnsignedInt(const char *key, unsigned int value);
		void SetPropInt(const char *key, int value);
		void SetPropFloat(const char *key, float value);
		void SetPropString(const char *key, const char *value);
		bool CheckPropExists(const char *key);

	private:
		char name[64];
		char className[64];
		IMap<SourceHook::String> *properties;
	};
}

#endif