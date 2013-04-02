#include "PLItemCallback.h"
#include "PLSkillCallback.h"
#include "QueryOperation.h"
#include "sdk\smsdk_ext.h"
#include "DBItem.h"
#include "List.h"
#include <sh_string.h>

using namespace SourceHook;

namespace War3Source {
	PLItemCallback::PLItemCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer, IList<IDBCharacter*> *DBCharacters) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
		this->DBCharacters = DBCharacters;
	}

	PLItemCallback::~PLItemCallback() {
	}

	void PLItemCallback::OnError(const char *query, const char *error, int errorCode) {
	}

	void PLItemCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
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

		IList<IDBItem*> *databaseItems = new List<IDBItem*>();

		for(unsigned int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(characterIdColumn, (int *)&characterId);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->CopyString(dataColumn, data, sizeof(data), NULL);

			IDBItem *dbItem = new DBItem(id, characterId, className, data);
			databaseItems->Append(dbItem);
		}

		String skillsQuery("SELECT * FROM war3_skills WHERE character_id IN (");

		unsigned int characterCount = this->DBCharacters->Size();

		char tempStr[64];

		for(unsigned int characterIndex = 0; characterIndex < characterCount; characterIndex++) {
			IDBCharacter *dbCharacter = this->DBCharacters->At(characterIndex);

			if(characterIndex != 0) {
				skillsQuery.append(",");
			}

			sprintf_s(tempStr, sizeof(tempStr), "'%d'", dbCharacter->GetID());
			skillsQuery.append(tempStr);
		}

		skillsQuery.append(")");

		META_CONPRINTF("Query is: %s\n", skillsQuery.c_str());

		IQueryCallback *skillsSelectCallback = new PLSkillCallback(this->playerLoader, this->databasePlayer, this->DBCharacters, databaseItems);
		QueryOperation *skillsSelectOp = new QueryOperation(skillsQuery.c_str(), skillsSelectCallback);

		dbi->AddToThreadQueue(skillsSelectOp, PrioQueue_Normal);
	}

	void PLItemCallback::OnCancel(const char *query) {
	}
}