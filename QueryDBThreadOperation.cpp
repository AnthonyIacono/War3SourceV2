#include "QueryDBThreadOperation.h"
#include "Globals.h"

namespace War3Source {
	QueryDBThreadOperation::QueryDBThreadOperation(const char *query, IQueryDBThreadOperationCallback *callback) {
		strcpy_s(this->query, sizeof(this->query), query);
		this->callback = callback;

		strcpy_s(this->error, sizeof(this->error), "");
		this->errorCode = 0;
		this->results = NULL;
	}

	IdentityToken_t *QueryDBThreadOperation::GetOwner() {
		return g_DBDriver->GetIdentity();
	}

	IDBDriver *QueryDBThreadOperation::GetDriver() {
		return g_DBDriver;
	}

	void QueryDBThreadOperation::RunThreadPart() {
		this->results = g_Database->DoQuery(this->query);

		if(this->results) {
			return;
		}

		const char *error = g_Database->GetError(&this->errorCode);
		strcpy_s(this->error, sizeof(this->error), error);
	}

	void QueryDBThreadOperation::CancelThinkPart() {
		if(this->results) {
			this->results->Destroy();
			this->results = NULL;
		}

		this->callback->OnCancel(this->query); 
	}

	void QueryDBThreadOperation::RunThinkPart() {
		if(NULL == this->results) {
			this->callback->OnError(this->query, this->error, this->errorCode);
			return;
		}

		this->callback->OnSuccess(this->query, this->results);
	}

	void QueryDBThreadOperation::Destroy() {
		if(this->results) {
			this->results->Destroy();
			this->results = NULL;
		}

		delete this;
	}
}