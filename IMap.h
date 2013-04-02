#ifndef __war3source_imap_h__
#define __war3source_imap_h__

#include <sh_vector.h>
#include <sh_string.h>

namespace War3Source {
	/**
	 * Represents a map of data (key value store)
	 */
	template <class T> class IMap {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Get a value from the map by key.
		 */
		virtual T GetValue(const char *key, T defaultValue) = 0;

		/**
		 * Set a value in the map by key.
		 */
		virtual void SetValue(const char *key, T value) = 0;

		/**
		 * Check if map contains a key.
		 */
		virtual bool CheckContainsKey(const char *key) = 0;
		
		/**
		 * Get a vector of keys
		 */
		virtual SourceHook::CVector<SourceHook::String> *GetKeys() = 0;
	};
}

#endif