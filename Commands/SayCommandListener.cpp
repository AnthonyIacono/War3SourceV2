#include "SayCommandListener.h"
#include "sdk\smsdk_ext.h"
#include <iostream>

namespace War3Source {
	SayCommandListener::SayCommandListener() {
	}

	SayCommandListener::~SayCommandListener() {
	}

	void SayCommandListener::Destroy() {
		delete this;
	}

	#if SOURCE_ENGINE >= SE_ORANGEBOX
	void SayCommandListener::OnSayCommand(const CCommand &command) {
	#else
	void SayCommandListener::OnSayCommand() {
		CCommand command;
	#endif
		const char *firstWord = command.Arg(1);

		if(strcmp(firstWord, "changecharacter") == 0) {
			RETURN_META(MRES_SUPERCEDE);
		}
		else if(strcmp(firstWord, "war3help") == 0) {
			RETURN_META(MRES_SUPERCEDE);
		}

		RETURN_META(MRES_IGNORED);
	}
}