#include "race.h"

#include <iostream>
#include <sh_vector.h>

Race::Race(const char *key, SourceHook::CVector<Skill*> skills) {
	strcpy_s(this->key, sizeof(this->key), key);
	this->skills = skills;
}