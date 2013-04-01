#include "PlayerBinder.h"
#include "Player.h"
#include "Character.h"
#include "List.h"
#include "IQuest.h"
#include "IItem.h"
#include "ISkill.h"
#include <iostream>

namespace War3Source {
	PlayerBinder::PlayerBinder(IDatabasePlayer *databasePlayer, IList<IDatabaseCharacter*> *databaseCharacters,
			IList<IDatabaseItem*> *databaseItems, IList<IDatabaseSkill*> *databaseSkills,
			IList<IDatabaseQuest*> *databaseQuests) {
		this->databasePlayer = databasePlayer;
		this->databaseCharacters = databaseCharacters;
		this->databaseItems = databaseItems;
		this->databaseSkills = databaseSkills;
		this->databaseQuests = databaseQuests;
	}

	PlayerBinder::~PlayerBinder() {
	}

	void PlayerBinder::Destroy() {
		delete this;
	}

	IPlayer *PlayerBinder::BindPlayerData() {
		IList<ICharacter*> *characterList = new List<ICharacter*>();
		ICharacter *activeCharacter = NULL;

		unsigned int activeCharacterId = this->databasePlayer->GetActiveCharacterID();

		unsigned int characterCount = this->databaseCharacters->Size();

		for(unsigned int characterIndex = 0; characterIndex < characterCount; characterIndex++) {
			IDatabaseCharacter *dbCharacter = this->databaseCharacters->At(characterIndex);

			unsigned int characterId = dbCharacter->GetID();

			IList<ISkill*> *skillList = new List<ISkill*>();
			IList<IItem*> *itemList = new List<IItem*>();
			IList<IQuest*> *questList = new List<IQuest*>();

			ICharacter *character = new Character("CHAR NAME", dbCharacter->GetClass(), dbCharacter->GetLevel(), dbCharacter->GetXP(), skillList, itemList, questList);

			if(activeCharacterId == characterId) {
				activeCharacter = character;
			}

			characterList->Append(character);
		}

		IPlayer *player = new Player(characterList, activeCharacter);
		return player;
	}
}