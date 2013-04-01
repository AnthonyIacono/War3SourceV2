#include "PLSkillSelectQueryDBThreadOperationCallback.h"
#include "QueryDBThreadOperation.h"
#include "sdk\smsdk_ext.h"
#include "DatabaseSkill.h"
#include "PlayerBinder.h"
#include "List.h"
#include <sh_string.h>

using namespace SourceHook;

namespace War3Source {
	PLSkillSelectQueryDBThreadOperationCallback::PLSkillSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader, IDatabasePlayer *databasePlayer, IList<IDatabaseCharacter*> *databaseCharacters, IList<IDatabaseItem*> *databaseItems) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
		this->databaseCharacters = databaseCharacters;
	}

	PLSkillSelectQueryDBThreadOperationCallback::~PLSkillSelectQueryDBThreadOperationCallback() {
	}

	void PLSkillSelectQueryDBThreadOperationCallback::OnError(const char *query, const char *error, int errorCode) {
	}

	void PLSkillSelectQueryDBThreadOperationCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		unsigned int idColumn, characterIdColumn, classColumn, levelColumn;

		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("character_id", &characterIdColumn);
		resultSet->FieldNameToNum("class", &classColumn);
		resultSet->FieldNameToNum("level", &levelColumn);

		unsigned int skillCount = resultSet->GetRowCount();

		unsigned int id, characterId, level;
		char className[64];

		IList<IDatabaseSkill*> *databaseSkills = new List<IDatabaseSkill*>();

		for(unsigned int skillIndex = 0; skillIndex < skillCount; skillIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(characterIdColumn, (int *)&characterId);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->GetInt(levelColumn, (int *)&level);

			IDatabaseSkill *dbSkill = new DatabaseSkill(id, characterId, className, level);
			databaseSkills->Append(dbSkill);
		}

		//IPlayerBinder *playerBinder = new PlayerBinder();
	}

	void PLSkillSelectQueryDBThreadOperationCallback::OnCancel(const char *query) {
	}
}