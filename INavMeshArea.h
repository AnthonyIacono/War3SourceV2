#ifndef __war3source_inavmesharea_h__
#define __war3source_inavmesharea_h__

namespace War3Source {
	class INavMeshArea {
	public:
		virtual unsigned int GetID() = 0;
		virtual unsigned int GetFlags() = 0;

		virtual float GetNWExtentX() = 0;
		virtual float GetNWExtentY() = 0;
		virtual float GetNWExtentZ() = 0;

		virtual float GetSEExtentX() = 0;
		virtual float GetSEExtentY() = 0;
		virtual float GetSEExtentZ() = 0;
	};
}

#endif