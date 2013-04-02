#ifndef __war3source_inavmeshconnection_h__
#define __war3source_inavmeshconnection_h__

#include "NavDirType.h"

namespace War3Source {
	/**
	 * Represents a loaded navigation mesh area connection.
	 */
	class INavMeshConnection {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the connecting area ID.
		 */
		virtual unsigned int GetConnectingAreaID() = 0;
		
		/**
		 * Retrieve the connection direction.
		 */
		virtual NavDirType GetDirection() = 0;
	};
}

#endif