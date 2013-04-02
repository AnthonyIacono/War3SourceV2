#ifndef __war3source_iplayerpersister_h__
#define __war3source_iplayerpersister_h__

namespace War3Source {
	class IPlayerPersister {
	public:
		virtual void Persist() = 0;
	};
}

#endif