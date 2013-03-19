#include "player.h"
#include <iostream>

#include "extension.h"

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