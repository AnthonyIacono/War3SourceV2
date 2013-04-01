#include "PLCharacterSelectQueryDBThreadOperationCallback.h"
#include "PLItemSelectQueryDBThreadOperationCallback.h"
#include "sdk/smsdk_ext.h"
#include "DatabaseCharacter.h"
#include "QueryDBThreadOperation.h"
#include "List.h"
#include <sh_string.h>

using namespace SourceMod;
using namespace SourceHook;

namespace War3Source {
	PLCharacterSelectQueryDBThreadOperationCallback::PLCharacterSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader, IDatabasePlayer *databasePlayer) {
		this->playerLoader = playerLoader;
		this->databasePlayer = databasePlayer;
	}

	PLCharacterSelectQueryDBThreadOperationCallback::~PLCharacterSelectQueryDBThreadOperationCallback() {
	}

	void PLCharacterSelectQueryDBThreadOperationCallback::OnError(const char *query, const char *error, int errorCode) {
		META_CONPRINTF("Error with query: %s\n", query);
	}
	
	void PLCharacterSelectQueryDBThreadOperationCallback::OnSuccess(const char *query, SourceMod::IQuery *results) {
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

		IList<IDatabaseCharacter*> *databaseCharacters = new List<IDatabaseCharacter*>();

		String itemQuery("SELECT * FROM war3_items WHERE character_id IN (");

		char tempStr[64];

		for(unsigned int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
			IResultRow *resultRow = resultSet->FetchRow();

			resultRow->GetInt(idColumn, (int *)&id);
			resultRow->GetInt(levelColumn, (int *)&level);
			resultRow->GetInt(xpColumn, (int *)&xp);
			resultRow->CopyString(classColumn, className, sizeof(className), NULL);
			resultRow->CopyString(nameColumn, name, sizeof(name), NULL);

			IDatabaseCharacter *dbCharacter = new DatabaseCharacter(id, this->databasePlayer->GetID(), className, name, level, xp);
			databaseCharacters->Append(dbCharacter);

			sprintf_s(tempStr, sizeof(tempStr), "'%d'", id);

			if(rowIndex != 0) {
				itemQuery.append(",");
			}

			itemQuery.append(tempStr);
		}

		itemQuery.append(")");

		META_CONPRINTF("Query is: %s\n", itemQuery.c_str());

		IQueryDBThreadOperationCallback *itemsSelectCallback = new PLItemSelectQueryDBThreadOperationCallback(this->playerLoader, this->databasePlayer, databaseCharacters);
		QueryDBThreadOperation *itemsSelectOp = new QueryDBThreadOperation(itemQuery.c_str(), itemsSelectCallback);

		dbi->AddToThreadQueue(itemsSelectOp, PrioQueue_Normal);
	}

	void PLCharacterSelectQueryDBThreadOperationCallback::OnCancel(const char *query) {
	}
}