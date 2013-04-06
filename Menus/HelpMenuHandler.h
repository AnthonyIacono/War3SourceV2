#ifndef __war3source_helpmenuhandler_h__
#define __war3source_helpmenuhandler_h__

#include "sdk\smsdk_ext.h"

namespace War3Source {
	class HelpMenuHandler : public IMenuHandler {
	public:
		HelpMenuHandler();
		~HelpMenuHandler();

		void OnMenuSelect2(IBaseMenu *menu, int client, unsigned int item, unsigned int item_on_page);
		void OnMenuDestroy(IBaseMenu *menu);
	};
}

#endif