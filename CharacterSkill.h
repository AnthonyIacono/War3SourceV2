#ifndef __war3source_characterskill_h__
#define __war3source_characterskill_h__

class Character;
class Skill;

class CharacterSkill {
public:
	CharacterSkill();
	~CharacterSkill();

private:
	Character *character;
	Skill *skill;
	int level;
};

#endif