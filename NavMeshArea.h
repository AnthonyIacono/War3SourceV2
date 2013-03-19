#ifndef __war3source_navmesharea_h__
#define __war3source_navmesharea_h__

#include "INavMeshArea.h"

namespace War3Source {
	class NavMeshArea : public INavMeshArea{
	public:
		NavMeshArea();
		~NavMeshArea();

		unsigned int GetID();
		unsigned int GetFlags();

		float GetNWExtentX();
		float GetNWExtentY();
		float GetNWExtentZ();

		float GetSEExtentX();
		float GetSEExtentY();
		float GetSEExtentZ();
	};
}

#endif