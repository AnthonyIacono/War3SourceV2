#include "PLItemSelectQueryDBThreadOperationCallback.h"
#include "PLSkillSelectQueryDBThreadOperationCallback.h"
#include "QueryDBThreadOperation.h"
#include "sdk\smsdk_ext.h"
#include "DatabaseItem.h"
#include "List.h"
#include <sh_string.h>

using namespace SourceHook;

namespace War3Source {
	PLItemSelectQueryDBThreadOperationCallback::PLItemSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader, IDatabasePlayer *databasePlayer, IList<IDatabaseCharacter*> *databaseCharacters) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
		this->databaseCharacters = databaseCharacters;
	}

	PLItemSelectQueryDBThreadOperationCallback::~PLItemSelectQueryDBThreadOperationCallback() {
	}

	void PLItemSelectQueryDBThreadOperationCallback::OnError(const char *query, const char *error, int errorCode) {
	}

	void PLItemSelectQueryDBThreadOperationCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		unsigned int idColumn, characterIdColumn, classColumn, dataColumn;

		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("character_id", &characterIdColumn);
		resultSet->FieldNameToNum("class", &classColumn);
		resultSet->FieldNameToNum("data", &dataColumn);

		unsigned int rowCount = resultSet->GetRowCount();

		unsigned int id, characterId;
		char className[64];
		char data[4096];

		IList<IDatabaseItem*> *databaseItems = new List<IDatabaseItem*>();

		for(unsigned int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(characterIdColumn, (int *)&characterId);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->CopyString(dataColumn, data, sizeof(data), NULL);

			IDatabaseItem *dbItem = new DatabaseItem(id, characterId, className, data);
			databaseItems->Append(dbItem);
		}

		String skillsQuery("SELECT * FROM war3_skills WHERE character_id IN (");

		unsigned int characterCount = this->databaseCharacters->Size();

		char tempStr[64];

		for(unsigned int characterIndex = 0; characterIndex < characterCount; characterIndex++) {
			IDatabaseCharacter *dbCharacter = this->databaseCharacters->At(characterIndex);

			if(characterIndex != 0) {
				skillsQuery.append(",");
			}

			sprintf_s(tempStr, sizeof(tempStr), "'%d'", dbCharacter->GetID());
			skillsQuery.append(tempStr);
		}

		skillsQuery.append(")");

		META_CONPRINTF("Query is: %s\n", skillsQuery.c_str());

		IQueryDBThreadOperationCallback *skillsSelectCallback = new PLSkillSelectQueryDBThreadOperationCallback(this->playerLoader, this->databasePlayer, this->databaseCharacters, databaseItems);
		QueryDBThreadOperation *skillsSelectOp = new QueryDBThreadOperation(skillsQuery.c_str(), skillsSelectCallback);

		dbi->AddToThreadQueue(skillsSelectOp, PrioQueue_Normal);
	}

	void PLItemSelectQueryDBThreadOperationCallback::OnCancel(const char *query) {
	}
}