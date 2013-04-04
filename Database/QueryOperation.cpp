#include "QueryOperation.h"
#include "Globals.h"

namespace War3Source {
	QueryOperation::QueryOperation(const char *query, IQueryCallback *callback) {
		StrCopy(this->query, sizeof(this->query), query);
		this->callback = callback;

		StrCopy(this->error, sizeof(this->error), "");
		this->errorCode = 0;
		this->results = NULL;
	}

	IdentityToken_t *QueryOperation::GetOwner() {
		return g_DBDriver->GetIdentity();
	}

	IDBDriver *QueryOperation::GetDriver() {
		return g_DBDriver;
	}

	void QueryOperation::RunThreadPart() {
		this->results = g_Database->DoQuery(this->query);

		if(this->results) {
			return;
		}

		const char *error = g_Database->GetError(&this->errorCode);
		StrCopy(this->error, sizeof(this->error), error);
	}

	void QueryOperation::CancelThinkPart() {
		if(this->results) {
			this->results->Destroy();
			this->results = NULL;
		}

		this->callback->OnCancel(this->query); 
	}

	void QueryOperation::RunThinkPart() {
		if(NULL == this->results) {
			this->callback->OnError(this->query, this->error, this->errorCode);
			return;
		}

		this->callback->OnSuccess(this->query, this->results);
	}

	void QueryOperation::Destroy() {
		if(this->results) {
			this->results->Destroy();
			this->results = NULL;
		}

		delete this;
	}
}