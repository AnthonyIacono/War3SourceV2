#ifndef __war3source_iquest_h__
#define __war3source_iquest_h__

namespace War3Source {
	class IQuest {
	public:
		virtual const char *GetName() = 0;
		virtual const char *GetClass() = 0;
	};
}

#endif