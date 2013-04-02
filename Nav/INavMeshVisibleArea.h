#ifndef __war3source_inavmeshvisiblearea_h__
#define __war3source_inavmeshvisiblearea_h__

namespace War3Source {
	/**
	 * Represents a visible area within (from) an area.
	 */
	class INavMeshVisibleArea {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the visible area ID.
		 */
		virtual unsigned int GetVisibleAreaID() = 0;

		/**
		 * Retrieve the attributes.
		 */
		virtual unsigned char GetAttributes() = 0;
	};
}

#endif