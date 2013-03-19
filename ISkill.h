#ifndef __war3source_iskill_h__
#define __war3source_iskill_h__

namespace War3Source {
	class ISkill {
	public:
		virtual const char *GetName() = 0;
		virtual int GetLevel() = 0;
	};
}

#endif