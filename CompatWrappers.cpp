#include "CompatWrappers.h"
#include "Globals.h"

#if SOURCE_ENGINE >= SE_ORANGEBOX
bool IsFlagSet(ConCommandBase *cmd, int flag) {
	return cmd->IsFlagSet(flag);
}

void InsertServerCommand(const char *buf) {
	engine->InsertServerCommand(buf);
}

ConCommandBase *FindCommandBase(const char *name) {
	return icvar->FindCommandBase(name);
}

ConCommand *FindCommand(const char *name) {
	return icvar->FindCommand(name);
}
#else
bool IsFlagSet(ConCommandBase *cmd, int flag) {
	return cmd->IsBitSet(flag);
}

void InsertServerCommand(const char *buf) {
	engine->InsertServerCommand(buf);
}

ConCommandBase *FindCommandBase(const char *name) {
	ConCommandBase *pBase = icvar->GetCommands();

	while(pBase) {
		if (strcmp(pBase->GetName(), name) == 0) {
			if (!pBase->IsCommand()) {
				return NULL;
			}

			return pBase;
		}
		pBase = const_cast<ConCommandBase *>(pBase->GetNext());
	}

	return NULL;
}

ConCommand *FindCommand(const char *name) {
	ConCommandBase *pBase = icvar->GetCommands();
		
	while (pBase) {
		if (strcmp(pBase->GetName(), name) == 0) {
			if (!pBase->IsCommand()) {
				return NULL;
			}

			return static_cast<ConCommand *>(pBase);
		}
		pBase = const_cast<ConCommandBase *>(pBase->GetNext());
	}
		
	return NULL;
}
#endif //SOURCE_ENGINE >= SE_ORANGEBOX