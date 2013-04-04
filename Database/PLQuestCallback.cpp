#include "PLQuestCallback.h"
#include "QueryOperation.h"
#include "sdk\smsdk_ext.h"
#include "PlayerBinder.h"
#include <sh_string.h>
#include "DBQuest.h"
#include "List.h"
#include "PlayerBinder.h"

namespace War3Source {
	PLQuestCallback::PLQuestCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer,
			IList<IDBCharacter*> *databaseCharacters, IList<IDBItem*> *databaseItems,
			IList<IDBSkill*> *databaseSkills) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
		this->databaseCharacters = databaseCharacters;
		this->databaseSkills = databaseSkills;
		this->databaseItems = databaseItems;
	}

	PLQuestCallback::~PLQuestCallback() {
	}

	void PLQuestCallback::OnError(const char *query, const char *error, int errorCode) {
	}

	void PLQuestCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		unsigned int idColumn, characterIdColumn, classColumn, dataColumn;

		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("character_id", &characterIdColumn);
		resultSet->FieldNameToNum("class", &classColumn);
		resultSet->FieldNameToNum("data", &dataColumn);

		unsigned int questCount = resultSet->GetRowCount();

		unsigned int id, characterId;
		char className[64];
		char data[4096];

		IList<IDBQuest*> *databaseQuests = new List<IDBQuest*>();

		for(unsigned int questIndex = 0; questIndex < questCount; questIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(characterIdColumn, (int *)&characterId);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->CopyString(dataColumn, data, sizeof(data), NULL);

			IDBQuest *dbQuest = new DBQuest(id, characterId, className, data);
			databaseQuests->Append(dbQuest);
		}

		PlayerBinder *binder = new PlayerBinder(this->databasePlayer, this->databaseCharacters, this->databaseItems, this->databaseSkills, databaseQuests);
		IPlayer *player = binder->BindPlayerData();

		this->playerLoader->GetCallback()->OnLoaded(this->databasePlayer->GetSteamID(), player);
	}

	void PLQuestCallback::OnCancel(const char *query) {
	}
}