#include "PLCharacterCallback.h"
#include "PLItemCallback.h"
#include "sdk/smsdk_ext.h"
#include "DBCharacter.h"
#include "QueryOperation.h"
#include "List.h"
#include <sh_string.h>

using namespace SourceMod;
using namespace SourceHook;

namespace War3Source {
	PLCharacterCallback::PLCharacterCallback(IPlayerLoader *playerLoader, IDBPlayer *databasePlayer) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
	}

	PLCharacterCallback::~PLCharacterCallback() {
	}

	void PLCharacterCallback::OnError(const char *query, const char *error, int errorCode) {
		META_CONPRINTF("Error with query: %s\n", query);
	}
	
	void PLCharacterCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		unsigned int idColumn, levelColumn, xpColumn, classColumn, nameColumn;

		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("level", &levelColumn);
		resultSet->FieldNameToNum("xp", &xpColumn);
		resultSet->FieldNameToNum("class", &classColumn);
		resultSet->FieldNameToNum("name", &nameColumn);

		unsigned int rowCount = resultSet->GetRowCount();

		unsigned int id, level, xp;
		char className[64];
		char name[64];

		IList<IDBCharacter*> *DBCharacters = new List<IDBCharacter*>();

		String itemQuery("SELECT * FROM war3_items WHERE character_id IN (");

		char tempStr[64];

		for(unsigned int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(levelColumn, (int *)&level);
			resultRow->GetInt(xpColumn, (int *)&xp);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->CopyString(nameColumn, name, sizeof(name), NULL);

			IDBCharacter *dbCharacter = new DBCharacter(id, this->databasePlayer->GetID(), className, name, level, xp);
			DBCharacters->Append(dbCharacter);

			sprintf_s(tempStr, sizeof(tempStr), "'%d'", id);

			if(rowIndex != 0) {
				itemQuery.append(",");
			}

			itemQuery.append(tempStr);
		}

		itemQuery.append(")");

		META_CONPRINTF("Query is: %s\n", itemQuery.c_str());

		IQueryCallback *itemsSelectCallback = new PLItemCallback(this->playerLoader, this->databasePlayer, DBCharacters);
		QueryOperation *itemsSelectOp = new QueryOperation(itemQuery.c_str(), itemsSelectCallback);

		dbi->AddToThreadQueue(itemsSelectOp, PrioQueue_Normal);
	}

	void PLCharacterCallback::OnCancel(const char *query) {
	}
}