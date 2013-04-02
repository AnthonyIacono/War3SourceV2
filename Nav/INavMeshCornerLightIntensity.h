#ifndef __war3source_inavmeshcornerlightintensity_h__
#define __war3source_inavmeshcornerlightintensity_h__

#include "NavCornerType.h"

namespace War3Source {
	/**
	 * Represents a loaded navigation mesh area corner light intensity.
	 */
	class INavMeshCornerLightIntensity {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the corner type.
		 */
		virtual NavCornerType GetCornerType() = 0;

		/**
		 * Retrieve the light intesity value.
		 */
		virtual float GetLightIntensity() = 0;
	};
}

#endif