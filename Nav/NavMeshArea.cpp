#include "NavMeshArea.h"

namespace War3Source {
	NavMeshArea::NavMeshArea(unsigned int id, unsigned int flags, unsigned int placeID,
			float nwExtentX, float nwExtentY, float nwExtentZ,
			float seExtentX, float seExtentY, float seExtentZ,
			float neCornerZ, float swCornerZ,
			IList<INavMeshConnection*> *connections, IList<INavMeshHidingSpot*> *hidingSpots, IList<INavMeshEncounterPath*> *encounterPaths,
			IList<INavMeshLadderConnection*> *ladderConnections, IList<INavMeshCornerLightIntensity*> *cornerLightIntensities,
			IList<INavMeshVisibleArea*> *visibleAreas, unsigned int inheritVisibilityFromAreaID,
			float earliestOccupyTimeFirstTeam, float earliestOccupyTimeSecondTeam, unsigned char unk01) {
				this->id = id;
				this->flags = flags;
				this->placeID = placeID;
				this->nwExtentX = nwExtentX;
				this->nwExtentY = nwExtentY;
				this->nwExtentZ = nwExtentZ;
				this->seExtentX = seExtentX;
				this->seExtentY = seExtentY;
				this->seExtentZ = seExtentZ;
				this->neCornerZ = neCornerZ;
				this->swCornerZ = swCornerZ;
				this->connections = connections;
				this->hidingSpots = hidingSpots;
				this->encounterPaths = encounterPaths;
				this->ladderConnections = ladderConnections;
				this->cornerLightIntensities = cornerLightIntensities;
				this->visibleAreas = visibleAreas;
				this->inheritVisibilityFromAreaID = inheritVisibilityFromAreaID;
				this->earliestOccupyTimeFirstTeam = earliestOccupyTimeFirstTeam;
				this->earliestOccupyTimeSecondTeam = earliestOccupyTimeSecondTeam;
				this->unk01 = unk01;
	}

	NavMeshArea::~NavMeshArea() {
		unsigned int connectionCount = this->connections->Size();

		for(unsigned int connectionIndex = 0; connectionIndex < connectionCount; connectionIndex++) {
			INavMeshConnection *connection = this->connections->At(connectionIndex);

			connection->Destroy();
		}

		this->connections->Destroy();

		unsigned int hidingSpotCount = this->hidingSpots->Size();

		for(unsigned int hidingSpotIndex = 0; hidingSpotIndex < hidingSpotCount; hidingSpotIndex++) {
			INavMeshHidingSpot *hidingSpot = this->hidingSpots->At(hidingSpotIndex);

			hidingSpot->Destroy();
		}

		this->hidingSpots->Destroy();

		unsigned int encounterPathCount = this->encounterPaths->Size();

		for(unsigned int encounterPathIndex = 0; encounterPathIndex < encounterPathCount; encounterPathIndex++) {
			INavMeshEncounterPath *encounterPath = this->encounterPaths->At(encounterPathIndex);

			encounterPath->Destroy();
		}

		this->encounterPaths->Destroy();

		unsigned int ladderConnectionCount = this->ladderConnections->Size();

		for(unsigned int ladderConnectionIndex = 0; ladderConnectionIndex < ladderConnectionCount; ladderConnectionIndex++) {
			INavMeshLadderConnection *ladderConnection = this->ladderConnections->At(ladderConnectionIndex);

			ladderConnection->Destroy();
		}

		this->ladderConnections->Destroy();

		unsigned int cornerLightIntensityCount = this->cornerLightIntensities->Size();

		for(unsigned int cornerLightIntensityIndex = 0; cornerLightIntensityIndex < cornerLightIntensityCount; cornerLightIntensityIndex++) {
			INavMeshCornerLightIntensity *cornerLightIntensity = this->cornerLightIntensities->At(cornerLightIntensityIndex);

			cornerLightIntensity->Destroy();
		}

		this->cornerLightIntensities->Destroy();

		unsigned int visibleAreaCount = this->visibleAreas->Size();

		for(unsigned int visibleAreaIndex = 0; visibleAreaIndex < visibleAreaCount; visibleAreaIndex++) {
			INavMeshVisibleArea *visibleArea = this->visibleAreas->At(visibleAreaIndex);

			visibleArea->Destroy();
		}

		this->visibleAreas->Destroy();
	}

	void NavMeshArea::Destroy() {
		delete this;
	}

	unsigned int NavMeshArea::GetID() {
		return this->id;
	}

	unsigned int NavMeshArea::GetFlags() {
		return this->flags;
	}

	unsigned int NavMeshArea::GetPlaceID() {
		return this->placeID;
	}

	float NavMeshArea::GetNWExtentX() {
		return this->nwExtentX;
	}

	float NavMeshArea::GetNWExtentY() {
		return this->nwExtentY;
	}
	
	float NavMeshArea::GetNWExtentZ() {
		return this->nwExtentZ;
	}

	float NavMeshArea::GetSEExtentX() {
		return this->seExtentX;
	}

	float NavMeshArea::GetSEExtentY() {
		return this->seExtentY;
	}

	float NavMeshArea::GetSEExtentZ() {
		return this->seExtentZ;
	}

	float NavMeshArea::GetEarliestOccupyTimeFirstTeam() {
		return this->earliestOccupyTimeFirstTeam;
	}

	float NavMeshArea::GetEarliestOccupyTimeSecondTeam() {
		return this->earliestOccupyTimeSecondTeam;
	}

	float NavMeshArea::GetNECornerZ() {
		return this->neCornerZ;
	}

	float NavMeshArea::GetSWCornerZ() {
		return this->swCornerZ;
	}

	IList<INavMeshConnection*> *NavMeshArea::GetConnections() {
		return this->connections;
	}

	IList<INavMeshHidingSpot*> *NavMeshArea::GetHidingSpots() {
		return this->hidingSpots;
	}

	IList<INavMeshEncounterPath*> *NavMeshArea::GetEncounterPaths() {
		return this->encounterPaths;
	}

	IList<INavMeshLadderConnection*> *NavMeshArea::GetLadderConnections() {
		return this->ladderConnections;
	}

	IList<INavMeshCornerLightIntensity*> *NavMeshArea::GetCornerLightIntensities() {
		return this->cornerLightIntensities;
	}

	IList<INavMeshVisibleArea*> *NavMeshArea::GetVisibleAreas() {
		return this->visibleAreas;
	}

	unsigned int NavMeshArea::GetInheritVisibilityFromAreaID() {
		return this->inheritVisibilityFromAreaID;
	}

	unsigned char NavMeshArea::GetUnk01() {
		return this->unk01;
	}
}