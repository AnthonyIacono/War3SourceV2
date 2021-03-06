#ifndef __war3source_idatabasequest_h__
#define __war3source_idatabasequest_h__

namespace War3Source {
	/**
	 * A quest loaded from the database.
	 */
	class IDBQuest {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;
		
		/**
		 * Retrieve the ID column.
		 */
		virtual unsigned int GetID() = 0;

		/**
		 * Retrieve the character ID column.
		 */
		virtual unsigned int GetCharacterID() = 0;

		/**
		 * Retrieve the class column.
		 */
		virtual const char *GetClass() = 0;

		/**
		 * Retrieve the data column.
		 */
		virtual const char *GetData() = 0;
	};
}

#endif