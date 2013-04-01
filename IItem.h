#ifndef __war3source_iitem_h__
#define __war3source_iitem_h__

namespace War3Source {
	class IItem {
	public:
		virtual const char *GetName() = 0;
	};
}

#endif