#ifndef __war3source_skill_h__
#define __war3source_skill_h__

class Race;

class Skill {
public:
	Skill(Race *race, const char *skill);
	~Skill();

private:
	Race *race;
	char skill[64];
};

#endif