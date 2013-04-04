#include "skill.h"
#include "Utils.h"

namespace War3Source {
	Skill::Skill(const char *name, const char *className, unsigned int level) {
		StrCopy(this->name, sizeof(this->name), name);
		StrCopy(this->className, sizeof(this->className), className);
		this->level = level;
	}
	
	Skill::~Skill() {
	}

	void Skill::Destroy() {
		delete this;
	}

	const char *Skill::GetName() {
		return this->name;
	}

	const char *Skill::GetClass() {
		return this->className;
	}

	int Skill::GetLevel() {
		return this->level;
	}
}