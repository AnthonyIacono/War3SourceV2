#ifndef __war3source_inavmesharea_h__
#define __war3source_inavmesharea_h__

#include "IList.h"
#include "INavMeshConnection.h"
#include "INavMeshHidingSpot.h"
#include "INavMeshEncounterPath.h"
#include "INavMeshLadderConnection.h"
#include "INavMeshCornerLightIntensity.h"
#include "INavMeshVisibleArea.h"

namespace War3Source {
	/**
	 * Represents a loaded geometric area in a navigation mesh.
	 */
	class INavMeshArea {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the area ID.
		 */
		virtual unsigned int GetID() = 0;

		/**
		 * Retrieve the area's flags.
		 */
		virtual unsigned int GetFlags() = 0;

		/**
		 * Retrieve the place ID of which this area subsides in.
		 */
		virtual unsigned int GetPlaceID() = 0;

		/**
		 * Retrieve the north-west extext X coordinate.
		 */
		virtual float GetNWExtentX() = 0;

		/**
		 * Retrieve the north-west extext Y coordinate.
		 */
		virtual float GetNWExtentY() = 0;

		/**
		 * Retrieve the north-west extext Z coordinate.
		 */
		virtual float GetNWExtentZ() = 0;

		/**
		 * Retrieve the south-east extext X coordinate.
		 */
		virtual float GetSEExtentX() = 0;

		/**
		 * Retrieve the south-east extext Y coordinate.
		 */
		virtual float GetSEExtentY() = 0;

		/**
		 * Retrieve the south-east extext Z coordinate.
		 */
		virtual float GetSEExtentZ() = 0;

		/**
		 * Retrieve the first team's earliest occupy time.
		 */
		virtual float GetEarliestOccupyTimeFirstTeam() = 0;

		/**
		 * Retrieve the second team's earliest occupy time.
		 */
		virtual float GetEarliestOccupyTimeSecondTeam() = 0;

		/**
		 * Retrieve the north-east corner Z coordinate.
		 */
		virtual float GetNECornerZ() = 0;

		/**
		 * Retrieve the south-west corner Z coordinate.
		 */
		virtual float GetSWCornerZ() = 0;

		/**
		 * Retrieve a list of loaded area connections.
		 */
		virtual IList<INavMeshConnection*> *GetConnections() = 0;

		/**
		 * Retrieve a list of loaded hiding spots.
		 */
		virtual IList<INavMeshHidingSpot*> *GetHidingSpots() = 0;

		/**
		 * Retrieve a list of loaded encounter paths.
		 */
		virtual IList<INavMeshEncounterPath*> *GetEncounterPaths() = 0;

		/**
		 * Retrieve a list of loaded ladder connections.
		 */
		virtual IList<INavMeshLadderConnection*> *GetLadderConnections() = 0;

		/**
		 * Retrieve a list of loaded corner light intensities.
		 */
		virtual IList<INavMeshCornerLightIntensity*> *GetCornerLightIntensities() = 0;

		/**
		 * Retrieve a list of loaded visible areas.
		 */
		virtual IList<INavMeshVisibleArea*> *GetVisibleAreas() = 0;

		/**
		 * Retrieve loaded inheritance visibility area ID.
		 */
		virtual unsigned int GetInheritVisibilityFromAreaID() = 0;

		/**
		 * Retrieve loaded unk01.
		 */
		virtual unsigned char GetUnk01() = 0;
	};
}

#endif