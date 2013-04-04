#include "NavMeshPlace.h"
#include "Utils.h"
#include "Utils.h"

namespace War3Source {
	NavMeshPlace::NavMeshPlace(unsigned int id, const char *name) {
		this->id = id;
		StrCopy(this->name, sizeof(this->name), name);
	}

	NavMeshPlace::~NavMeshPlace() {
	}

	void NavMeshPlace::Destroy() {
		delete this;
	}

	const char *NavMeshPlace::GetName() {
		return this->name;
	}

	unsigned int NavMeshPlace::GetID() {
		return this->id;
	}
}