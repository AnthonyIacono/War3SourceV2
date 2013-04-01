#include "ConnectDBThreadOperation.h"

namespace War3Source {
	ConnectDBThreadOperation::ConnectDBThreadOperation(IDBDriver *dbDriver, const DatabaseInfo *dbInfo, IConnectDBThreadOperationCallback *callback) {
		this->dbDriver = dbDriver;
		this->dbInfo = dbInfo;
		this->callback = callback;

		strcpy_s(this->connectionError, sizeof(this->connectionError), "");
		this->database = NULL;
	}

	IdentityToken_t *ConnectDBThreadOperation::GetOwner() {
		return this->dbDriver->GetIdentity();
	}

	IDBDriver *ConnectDBThreadOperation::GetDriver() {
		return this->dbDriver;
	}

	void ConnectDBThreadOperation::RunThreadPart() {
		this->database = this->dbDriver->Connect(this->dbInfo, false, this->connectionError, sizeof(this->connectionError));
	}

	void ConnectDBThreadOperation::CancelThinkPart() {
		if(this->database) {
			this->database->Close();
			this->database = NULL;
		}

		this->callback->OnCancel(this->dbDriver, this->dbInfo); 
	}

	void ConnectDBThreadOperation::RunThinkPart() {
		if(NULL == this->database) {
			this->callback->OnError(this->dbDriver, this->dbInfo, this->connectionError);
			return;
		}

		META_CONPRINTF("Got db...\n");

		this->callback->OnSuccess(this->dbDriver, this->dbInfo, this->database);
	}

	void ConnectDBThreadOperation::Destroy() {
		delete this;
	}
}