#ifndef __war3source_iplayer_h__
#define __war3source_iplayer_h__

#include "IList.h"
#include "ICharacter.h"

namespace War3Source {
	class IPlayer {
	public:
		virtual IList<ICharacter*> *GetCharacterList() = 0;
		virtual ICharacter *GetActiveCharacter() = 0;
	};
}

#endif