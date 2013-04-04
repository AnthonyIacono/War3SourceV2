#ifndef __war3source_race_h__
#define __war3source_race_h__

class Skill;

#include "Utils.h"
#include <sh_vector.h>

class Race {
public:
	Race(const char *key, SourceHook::CVector<Skill*> skills);
	~Race();

private:
	char key[64];
	SourceHook::CVector<Skill*> skills;
};

#endif