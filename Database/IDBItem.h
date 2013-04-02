#ifndef __war3source_idatabaseitem_h__
#define __war3source_idatabaseitem_h__

namespace War3Source {
	/**
	 * An item loaded from the database.
	 */
	class IDBItem {
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