#include "NavMeshEncounterPath.h"

namespace War3Source {
	NavMeshEncounterPath::NavMeshEncounterPath(unsigned int fromAreaID, NavDirType fromDirection, unsigned int toAreaID, NavDirType toDirection, IList<INavMeshEncounterSpot*> *encounterSpots) {
		this->fromAreaID = fromAreaID;
		this->fromDirection = fromDirection;
		this->toAreaID = toAreaID;
		this->toDirection = toDirection;
		this->encounterSpots = encounterSpots;
	}
	
	NavMeshEncounterPath::~NavMeshEncounterPath() {
		unsigned int encounterSpotCount = this->encounterSpots->Size();

		for(unsigned int encounterSpotIndex = 0; encounterSpotIndex < encounterSpotCount; encounterSpotIndex++) {
			INavMeshEncounterSpot *encounterSpot = this->encounterSpots->At(encounterSpotIndex);

			encounterSpot->Destroy();
		}

		this->encounterSpots->Destroy();
	}

	void NavMeshEncounterPath::Destroy() {
		delete this;
	}

	unsigned int NavMeshEncounterPath::GetFromAreaID() {
		return this->fromAreaID;
	}

	NavDirType NavMeshEncounterPath::GetFromDirection() {
		return this->fromDirection;
	}

	unsigned int NavMeshEncounterPath::GetToAreaID() {
		return this->toAreaID;
	}

	NavDirType NavMeshEncounterPath::GetToDirection() {
		return this->toDirection;
	}

	IList<INavMeshEncounterSpot*> *NavMeshEncounterPath::GetEncounterSpots() {
		return this->encounterSpots;
	}
}