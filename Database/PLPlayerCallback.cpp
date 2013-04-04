#include "PLPlayerCallback.h"
#include "PLCharacterCallback.h"
#include "sdk\smsdk_ext.h"
#include <IDBDriver.h>
#include <sh_string.h>
#include "QueryOperation.h"
#include "DBPlayer.h"

using namespace SourceMod;
using namespace SourceHook;

namespace War3Source {
	PLPlayerCallback::PLPlayerCallback(IPlayerLoader *playerLoader) {
		this->playerLoader = playerLoader;
	}

	PLPlayerCallback::~PLPlayerCallback() {
	}

	void PLPlayerCallback::OnError(const char *query, const char *error, int errorCode) {
		META_CONPRINTF("Error with query: %s", query);
	}

	void PLPlayerCallback::OnSuccess(const char *query, IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		if(!resultSet->GetRowCount()) {
			this->playerLoader->GetCallback()->OnNotFound(this->playerLoader->GetSteamID());
			return;
		}

		unsigned int idColumn, activeCharacterIdColumn;
		resultSet->FieldNameToNum("id", &idColumn);
		resultSet->FieldNameToNum("active_character_id", &activeCharacterIdColumn);

		IResultRow *resultRow = resultSet->FetchRow();

		unsigned int id, activeCharacterId;
		resultRow->GetInt(idColumn, (int*)&id);
		resultRow->GetInt(activeCharacterIdColumn, (int*)&activeCharacterId);

		IDBPlayer *dbPlayer = new DBPlayer(id, this->playerLoader->GetSteamID(), activeCharacterId);

		char charactersQuery[256];
		sprintf_s(charactersQuery, sizeof(charactersQuery), "SELECT * FROM war3_characters WHERE player_id='%d'", id);

		IQueryCallback *characterSelectCallback = new PLCharacterCallback(this->playerLoader, dbPlayer);
		QueryOperation *characterSelectOp = new QueryOperation(charactersQuery, characterSelectCallback);

		dbi->AddToThreadQueue(characterSelectOp, PrioQueue_Normal);
	}

	void PLPlayerCallback::OnCancel(const char *query) {
		META_CONPRINTF("Cancelled: %s", query);
	}
}