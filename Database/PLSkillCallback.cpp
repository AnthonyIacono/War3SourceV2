#include "PLSkillCallback.h"
#include "QueryOperation.h"
#include "sdk\smsdk_ext.h"
#include "DBSkill.h"
#include "PlayerBinder.h"
#include "List.h"
#include <sh_string.h>
#include "PLQuestCallback.h"

using namespace SourceHook;

namespace War3Source {
	PLSkillCallback::PLSkillCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer, IList<IDBCharacter*> *databaseCharacters, IList<IDBItem*> *databaseItems) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
		this->databaseCharacters = databaseCharacters;
		this->databaseItems = databaseItems;
	}

	PLSkillCallback::~PLSkillCallback() {
	}

	void PLSkillCallback::OnError(const char *query, const char *error, int errorCode) {
	}

	void PLSkillCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		unsigned int idColumn, characterIdColumn, classColumn, levelColumn;

		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("character_id", &characterIdColumn);
		resultSet->FieldNameToNum("class", &classColumn);
		resultSet->FieldNameToNum("level", &levelColumn);

		unsigned int skillCount = resultSet->GetRowCount();

		unsigned int id, characterId, level;
		char className[64];

		IList<IDBSkill*> *databaseSkills = new List<IDBSkill*>();

		for(unsigned int skillIndex = 0; skillIndex < skillCount; skillIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(characterIdColumn, (int *)&characterId);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->GetInt(levelColumn, (int *)&level);

			IDBSkill *dbSkill = new DBSkill(id, characterId, className, level);
			databaseSkills->Append(dbSkill);
		}

		String questsQuery("SELECT * FROM war3_quests WHERE character_id IN (");

		unsigned int characterCount = this->databaseCharacters->Size();

		char tempStr[64];

		for(unsigned int characterIndex = 0; characterIndex < characterCount; characterIndex++) {
			IDBCharacter *dbCharacter = this->databaseCharacters->At(characterIndex);

			if(characterIndex != 0) {
				questsQuery.append(",");
			}

			sprintf_s(tempStr, sizeof(tempStr), "'%d'", dbCharacter->GetID());
			questsQuery.append(tempStr);
		}

		questsQuery.append(")");

		IQueryCallback *questCallback = new PLQuestCallback(this->playerLoader,
			this->databasePlayer, this->databaseCharacters, this->databaseItems,
			databaseSkills);

		QueryOperation *questSelectOp = new QueryOperation(questsQuery.c_str(), questCallback);

		dbi->AddToThreadQueue(questSelectOp, PrioQueue_Normal);
	}

	void PLSkillCallback::OnCancel(const char *query) {
	}
}