#include "HelpMenuHandler.h"

namespace War3Source {
	HelpMenuHandler::HelpMenuHandler() {
	}

	HelpMenuHandler::~HelpMenuHandler() {
	}

	void HelpMenuHandler::OnMenuSelect2(IBaseMenu *menu, int client, unsigned int item, unsigned int item_on_page) {
		META_CONPRINTF("CALLBACK: client is %d and item is %d\n", client, item);
		ItemDrawInfo i;
		const char *info = menu->GetItemInfo(item, &i);
		META_CONPRINTF("INFO: %s\n", info);
	}

	void HelpMenuHandler::OnMenuDestroy(IBaseMenu *menu) {
		delete this;
	}
}