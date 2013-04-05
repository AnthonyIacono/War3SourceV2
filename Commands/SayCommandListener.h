#ifndef __war3source_saycommandlistener_h__
#define __war3source_saycommandlistener_h__

#include "ISayCommandListener.h"

namespace War3Source {
	class SayCommandListener : public ISayCommandListener {
	public:
		SayCommandListener();
		~SayCommandListener();

		void Destroy();

		#if SOURCE_ENGINE >= SE_ORANGEBOX
		void OnSayCommand(const CCommand &command);
		#else
		void OnSayCommand();
		#endif
	};
}


#endif