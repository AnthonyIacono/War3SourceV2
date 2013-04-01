#include "PLSelectQueryDBThreadOperationCallback.h"
#include "sdk\smsdk_ext.h"
#include <IDBDriver.h>
#include <sh_string.h>
#include "PLCharacterSelectQueryDBThreadOperationCallback.h"
#include "QueryDBThreadOperation.h"
#include "DatabasePlayer.h"

using namespace SourceMod;
using namespace SourceHook;

namespace War3Source {
	PLSelectQueryDBThreadOperationCallback::PLSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader) {
		this->playerLoader = playerLoader;
	}

	PLSelectQueryDBThreadOperationCallback::~PLSelectQueryDBThreadOperationCallback() {
	}

	void PLSelectQueryDBThreadOperationCallback::OnError(const char *query, const char *error, int errorCode) {
		META_CONPRINTF("Error with query: %s", query);
	}

	void PLSelectQueryDBThreadOperationCallback::OnSuccess(const char *query, IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		if(!resultSet->GetRowCount()) {
			this->playerLoader->GetCallback()->OnNotFound(this->playerLoader->GetSteamID());
		}

		unsigned int idColumn, activeCharacterIdColumn;
		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("active_character_id", &activeCharacterIdColumn);

		IResultRow *resultRow = resultSet->FetchRow();

		unsigned int id, activeCharacterId;
		resultRow->GetInt(idColumn, (int*)&id);
		resultRow->GetInt(activeCharacterIdColumn, (int*)&activeCharacterId);

		IDatabasePlayer *dbPlayer = new DatabasePlayer(id, this->playerLoader->GetSteamID(), activeCharacterId);

		char charactersQuery[256];
		sprintf_s(charactersQuery, sizeof(charactersQuery), "SELECT * FROM war3_characters WHERE player_id='%d'", id);

		META_CONPRINTF("Character query\n");

		IQueryDBThreadOperationCallback *characterSelectCallback = new PLCharacterSelectQueryDBThreadOperationCallback(this->playerLoader, dbPlayer);
		QueryDBThreadOperation *characterSelectOp = new QueryDBThreadOperation(charactersQuery, characterSelectCallback);

		dbi->AddToThreadQueue(characterSelectOp, PrioQueue_Normal);
	}

	void PLSelectQueryDBThreadOperationCallback::OnCancel(const char *query) {
		META_CONPRINTF("Cancelled: %s", query);
	}
}