#include "SayCommandListener.h"
#include "sdk\smsdk_ext.h"
#include <iostream>
#include "Globals.h"
#include "HelpMenuHandler.h"

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
		int clientIndex = g_ClientCommandListener->GetCommandClient();

		META_CONPRINTF("Client index should be: %d\n", clientIndex);

		const char *firstWord = command.Arg(1);

		if(strcmp(firstWord, "changecharacter") == 0) {
			RETURN_META(MRES_SUPERCEDE);
		}
		else if(strcmp(firstWord, "war3help") == 0) {
			IMenuStyle *menuStyle = menus->GetDefaultStyle();

			HelpMenuHandler *handler = new HelpMenuHandler();
			IBaseMenu *menu = menuStyle->CreateMenu(handler);
			ItemDrawInfo i;
			i.display = "Testing";
			menu->AppendItem("Test", i);

			menu->Display(clientIndex, 0);

			RETURN_META(MRES_SUPERCEDE);
		}

		RETURN_META(MRES_IGNORED);
	}
}