#include "NavMeshEncounterSpot.h"

namespace War3Source {
	NavMeshEncounterSpot::NavMeshEncounterSpot(unsigned int orderID, float parametricDistance) {
		this->orderID = orderID;
		this->parametricDistance = parametricDistance;
	}

	NavMeshEncounterSpot::~NavMeshEncounterSpot() {
	}

	void NavMeshEncounterSpot::Destroy() {
		delete this;
	}

	unsigned int NavMeshEncounterSpot::GetOrderID() {
		return this->orderID;
	}

	float NavMeshEncounterSpot::GetParametricDistance() {
		return this->parametricDistance;
	}
}