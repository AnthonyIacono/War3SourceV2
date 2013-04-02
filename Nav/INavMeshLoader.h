#ifndef __war3source_inavmeshloader_h__
#define __war3source_inavmeshloader_h__

#include "INavMesh.h"

namespace War3Source {
	/**
	 * Represents a Source Engine navigation mesh loader.
	 */
	class INavMeshLoader {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Load a navigation mesh, errors are outputted to error and will be truncated to errorMaxlen.
		 */
		virtual INavMesh *Load(char *error, int errorMaxlen) = 0;
	};
}

#endif