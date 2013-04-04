#ifndef __war3source_map_h__
#define __war3source_map_h__

#include "IMap.h"
#include "List.h"
#include <sh_string.h>

using namespace SourceHook;

namespace War3Source {
	template <class T> class Map : public IMap<T> {
	public:
		struct MapItem {
			SourceHook::String key;
			T value;
		};

		Map() {
			this->items = new List<MapItem*>();
			this->keys = new SourceHook::CVector<String>();
		}

		~Map() {
			unsigned int itemCount = this->items->Size();

			for(unsigned int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
				MapItem *i = this->items->At(itemIndex);

				delete i;
			}

			delete this->items;
			delete this->keys;
		}

		void Destroy() {
			delete this;
		}

		T GetValue(const char *key, T defaultValue) {
			unsigned int itemCount = this->items->Size();

			for(unsigned int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
				MapItem *i = this->items->At(itemIndex);

				if(i->key.compare(key) != 0) {
					continue;
				}

				return i->value;
			}

			return defaultValue;
		}

		void SetValue(const char *key, T value) {
			// First we try to update the value if it's already in items.
			unsigned int itemCount = this->items->Size();

			for(unsigned int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
				MapItem *i = this->items->At(itemIndex);

				if(i->key.compare(key) != 0) {
					continue;
				}

				i->value = value;
				return;
			}

			MapItem *mapItem = new MapItem;

			mapItem->key.assign(key);
			mapItem->value = value;

			this->items->Append(mapItem);

			this->keys->push_back(key);
		}

		bool CheckContainsKey(const char *key) {
			unsigned int keyCount = this->keys->size();

			for(unsigned int keyIndex = 0; keyIndex < keyCount; keyIndex++) {
				String curKey = this->keys->at(keyIndex);

				if(curKey.compare(key) != 0) {
					continue;
				}

				return true;
			}

			return false;
		}
		
		SourceHook::CVector<SourceHook::String> *GetKeys() {
			return this->keys;
		}

	private:
		IList<MapItem*> *items;
		SourceHook::CVector<SourceHook::String> *keys;
	};
}

#endif