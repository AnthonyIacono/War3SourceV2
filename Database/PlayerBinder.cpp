#include "PlayerBinder.h"
#include "Player.h"
#include "Character.h"
#include "List.h"
#include "Quest.h"
#include "Item.h"
#include "Skill.h"
#include "Utils.h"
#include <sh_string.h>
#include "Map.h"
#include <KeyValues.h>
#include "sdk\smsdk_ext.h"
using namespace SourceHook;

namespace War3Source {
	PlayerBinder::PlayerBinder(IDBPlayer *databasePlayer, IList<IDBCharacter*> *dbCharacters,
			IList<IDBItem*> *databaseItems, IList<IDBSkill*> *databaseSkills,
			IList<IDBQuest*> *databaseQuests) {
		this->databasePlayer = databasePlayer;
		this->dbCharacters = dbCharacters;
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
		unsigned int characterCount = this->dbCharacters->Size();
		unsigned int skillCount = this->databaseSkills->Size();
		unsigned int questCount = this->databaseQuests->Size();
		unsigned int itemCount = this->databaseItems->Size();

		// Loop through the database characters
		for(unsigned int characterIndex = 0; characterIndex < characterCount; characterIndex++) {
			IDBCharacter *dbCharacter = this->dbCharacters->At(characterIndex);

			// Retrieve the ID column from dbCharacter
			unsigned int characterId = dbCharacter->GetID();

			// Create lists for ISkill's, IItem's, and IQuest's
			IList<ISkill*> *skillList = new List<ISkill*>();
			IList<IItem*> *itemList = new List<IItem*>();
			IList<IQuest*> *questList = new List<IQuest*>();

			// Loop through the database items and determine which pertain to dbCharacter
			for(unsigned int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
				IDBItem *dbItem = this->databaseItems->At(itemIndex);

				// If the item doesn't belong to dbCharacter, skip it
				if(dbItem->GetCharacterID() != characterId) {
					continue;
				}

				IMap<String> *properties = this->_ParseKVToMap(dbItem->GetData());

				IItem *item = new Item("ITEM NAME", dbItem->GetClass(), properties);

				itemList->Append(item);
			}

			// Loop through the database skills and determine which pertain to dbCharacter
			for(unsigned int skillIndex = 0; skillIndex < skillCount; skillIndex++) {
				IDBSkill *dbSkill = this->databaseSkills->At(skillIndex);

				// If the item doesn't belong to dbCharacter, skip it
				if(dbSkill->GetCharacterID() != characterId) {
					continue;
				}

				ISkill *skill = new Skill("SKILL NAME", dbSkill->GetClass(), dbSkill->GetLevel());
				skillList->Append(skill);
			}

			// Loop through the database quests and determine which pertain to dbCharacter
			for(unsigned int questIndex = 0; questIndex < questCount; questIndex++) {
				IDBQuest *dbQuest = this->databaseQuests->At(questIndex);

				// If the item doesn't belong to dbCharacter, skip it
				if(dbQuest->GetCharacterID() != characterId) {
					continue;
				}

				IMap<String> *properties = this->_ParseKVToMap(dbQuest->GetData());

				IQuest *quest = new Quest("QUEST NAME", dbQuest->GetClass(), properties);
				questList->Append(quest);
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

	IMap<String> *PlayerBinder::_ParseKVToMap(const char *propertiesData) {
		KeyValues *keyValues = new KeyValues("Properties");
		keyValues->LoadFromBuffer("Properties", propertiesData);

		IMap<String> *properties = new Map<String>();

		KeyValues *subKey = keyValues->GetFirstSubKey();
				
		while(subKey != NULL) {
			const char *n = subKey->GetName();
			const char *v = subKey->GetString();
				
			properties->SetValue(n, v);

			subKey = subKey->GetNextKey();
		}

		keyValues->deleteThis();

		return properties;
	}
}