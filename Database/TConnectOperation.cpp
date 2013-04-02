#include "ConnectOperation.h"

namespace War3Source {
	ConnectOperation::ConnectOperation(IDBDriver *dbDriver, const DatabaseInfo *dbInfo, IConnectCallback *callback) {
		this->dbDriver = dbDriver;
		this->dbInfo = dbInfo;
		this->callback = callback;

		strcpy_s(this->connectionError, sizeof(this->connectionError), "");
		this->database = NULL;
	}

	IdentityToken_t *ConnectOperation::GetOwner() {
		return this->dbDriver->GetIdentity();
	}

	IDBDriver *ConnectOperation::GetDriver() {
		return this->dbDriver;
	}

	void ConnectOperation::RunThreadPart() {
		this->database = this->dbDriver->Connect(this->dbInfo, false, this->connectionError, sizeof(this->connectionError));
	}

	void ConnectOperation::CancelThinkPart() {
		if(this->database) {
			this->database->Close();
			this->database = NULL;
		}

		this->callback->OnCancel(this->dbDriver, this->dbInfo); 
	}

	void ConnectOperation::RunThinkPart() {
		if(NULL == this->database) {
			this->callback->OnError(this->dbDriver, this->dbInfo, this->connectionError);
			return;
		}

		META_CONPRINTF("Got db...\n");

		this->callback->OnSuccess(this->dbDriver, this->dbInfo, this->database);
	}

	void ConnectOperation::Destroy() {
		delete this;
	}
}