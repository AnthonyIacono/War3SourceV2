#include "PLSelectQueryDBThreadOperationCallback.h"
#include "sdk\smsdk_ext.h"
#include <IDBDriver.h>

using namespace SourceMod;

namespace War3Source {
	PLSelectQueryDBThreadOperationCallback::PLSelectQueryDBThreadOperationCallback(IPlayerLoader *playerLoader) {
		this->playerLoader = playerLoader;
		strcpy_s(this->steamID, sizeof(this->steamID), steamID);
	}

	PLSelectQueryDBThreadOperationCallback::~PLSelectQueryDBThreadOperationCallback() {
	}

	void PLSelectQueryDBThreadOperationCallback::OnError(const char *query, const char *error, int errorCode) {
		META_CONPRINTF("Error with query: %s", query);
	}

	void PLSelectQueryDBThreadOperationCallback::OnSuccess(const char *query, IQuery *results) {
		IResultSet *resultSet = results->GetResultSet();

		if(!resultSet->GetRowCount()) {
			this->playerLoader->GetCallback()->OnNotFound(this->steamID);
		}

		META_CONPRINTF("Success!! Row count: %d", resultSet->GetRowCount());
	}

	void PLSelectQueryDBThreadOperationCallback::OnCancel(const char *query) {
		META_CONPRINTF("Cancelled: %s", query);
	}
}