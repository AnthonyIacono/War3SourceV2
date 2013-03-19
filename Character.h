#ifndef __war3source_character_h__
#define __war3source_character_h__

#include <sh_vector.h>

class Player;
class Skill;
class Race;
class CharacterSkill;

class Character {
public:
	Character(const char *name, Player *player, Race *race, SourceHook::CVector<CharacterSkill*> skills, int xp);
	~Character();

private:
	char name[128];
	Player *player;
	Race *race;
	SourceHook::CVector<CharacterSkill*> skills;
	int xp;
};

#endif