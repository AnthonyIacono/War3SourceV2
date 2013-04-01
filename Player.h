#ifndef __war3source_player_h__
#define __war3source_player_h__

#include "IList.h"
#include "ICharacter.h"
#include "IPlayer.h"

namespace War3Source {
	class Player : public IPlayer {
	public:
		Player(IList<ICharacter*> *characterList, ICharacter *activeCharacter);
		~Player();

		IList<ICharacter*> *GetCharacterList();
		ICharacter *GetActiveCharacter();

	private:
		IList<ICharacter*> *characterList;
		ICharacter *activeCharacter;
	};
}

#endif