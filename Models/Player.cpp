#include "Player.h"
#include <iostream>

namespace War3Source {
	Player::Player(IList<ICharacter*> *characterList, ICharacter *activeCharacter) {
		this->characterList = characterList;
		this->activeCharacter = activeCharacter;
	}

	Player::~Player() {
	}

	IList<ICharacter*> *Player::GetCharacterList() {
		return this->characterList;
	}

	ICharacter *Player::GetActiveCharacter() {
		return this->activeCharacter;
	}
}