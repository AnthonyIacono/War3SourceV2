#ifndef __war3source_inavmeshplace_h__
#define __war3source_inavmeshplace_h__

namespace War3Source {
	/**
	 * Represents a loaded place within a navigation mesh.
	 */
	class INavMeshPlace {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the place's name.
		 */
		virtual const char *GetName() = 0;

		/**
		 * Retrieve the place's ID.
		 */
		virtual unsigned int GetID() = 0;
	};
}

#endif