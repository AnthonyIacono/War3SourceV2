#ifndef __war3source_iquest_h__
#define __war3source_iquest_h__

#include <sh_string.h>

namespace War3Source {
	/**
	 * Represents a playable quest.
	 */
	class IQuest {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the name of the item.
		 */
		virtual const char *GetName() = 0;

		/**
		 * Retrieve the class of the item.
		 */
		virtual const char *GetClass() = 0;
		
		/**
		 * Get property as an unsigned int.
		 */
		virtual unsigned int GetPropUnsignedInt(const char *key, unsigned int defaultValue, bool *propExists) = 0;

		/**
		 * Get property as an int.
		 */
		virtual int GetPropInt(const char *key, int defaultValue, bool *propExists) = 0;

		/**
		 * Get property as a float.
		 */
		virtual float GetPropFloat(const char *key, float defaultValue, bool *propExists) = 0;

		/**
		 * Get property as a string.
		 */
		virtual SourceHook::String GetPropString(const char *key, SourceHook::String defaultValue, bool *propExists) = 0;

		/**
		 * Set property from an unsigned int.
		 */
		virtual void SetPropUnsignedInt(const char *key, unsigned int value) = 0;

		/**
		 * Set property from an int.
		 */
		virtual void SetPropInt(const char *key, int value) = 0;

		/**
		 * Set property from a float.
		 */
		virtual void SetPropFloat(const char *key, float value) = 0;

		/**
		 * Set property from a string.
		 */
		virtual void SetPropString(const char *key, const char *value) = 0;

		/**
		 * Check if a property exists.
		 */
		virtual bool CheckPropExists(const char *key) = 0;
	};
}

#endif