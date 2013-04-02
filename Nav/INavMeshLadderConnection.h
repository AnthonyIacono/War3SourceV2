#ifndef __war3source_inavmeshladderconnection_h__
#define __war3source_inavmeshladderconnection_h__

#include "NavLadderDirType.h"

namespace War3Source {
	/**
	 * Represents a loaded ladder connection within an area.
	 */
	class INavMeshLadderConnection {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the connecting ladder ID.
		 */
		virtual unsigned int GetConnectingLadderID() = 0;

		/**
		 * Retrieve the direction.
		 */
		virtual NavLadderDirType GetDirection() = 0;
	};
}

#endif