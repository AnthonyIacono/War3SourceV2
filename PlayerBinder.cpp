#include "PlayerBinder.h"
#include "Player.h"
#include "Character.h"
#include "List.h"
#include "IQuest.h"
#include "Item.h"
#include "ISkill.h"
#include <iostream>
#include <sh_string.h>
#include "Map.h"

using namespace SourceHook;

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
		// First we need to create a list of ICharacter's assume NULL active character.
		IList<ICharacter*> *characterList = new List<ICharacter*>();
		ICharacter *activeCharacter = NULL;

		// Retrieve the active character ID column from databasePlayer
		unsigned int activeCharacterId = this->databasePlayer->GetActiveCharacterID();

		// Get the counts of the database collections (for looping)
		unsigned int characterCount = this->databaseCharacters->Size();
		unsigned int skillCount = this->databaseSkills->Size();
		unsigned int questCount = this->databaseQuests->Size();
		unsigned int itemCount = this->databaseItems->Size();

		// Loop through the database characters
		for(unsigned int characterIndex = 0; characterIndex < characterCount; characterIndex++) {
			IDatabaseCharacter *dbCharacter = this->databaseCharacters->At(characterIndex);

			// Retrieve the ID column from dbCharacter
			unsigned int characterId = dbCharacter->GetID();

			// Create lists for ISkill's, IItem's, and IQuest's
			IList<ISkill*> *skillList = new List<ISkill*>();
			IList<IItem*> *itemList = new List<IItem*>();
			IList<IQuest*> *questList = new List<IQuest*>();

			// Loop through the database items and determine which pertain to dbCharacter
			for(unsigned int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
				IDatabaseItem *dbItem = this->databaseItems->At(itemIndex);

				// If the item doesn't belong to dbCharacter, skip it
				if(dbItem->GetCharacterID() != characterId) {
					continue;
				}

				IMap<String> *properties = new Map<String>();
				IItem *item = new Item("ITEM NAME", dbItem->GetClass(), properties);

				itemList->Append(item);
			}

			ICharacter *character = new Character("CHAR NAME", dbCharacter->GetClass(),
				dbCharacter->GetLevel(), dbCharacter->GetXP(), skillList, itemList, questList);

			if(activeCharacterId == characterId) {
				activeCharacter = character;
			}

			characterList->Append(character);
		}

		IPlayer *player = new Player(characterList, activeCharacter);
		return player;
	}
}