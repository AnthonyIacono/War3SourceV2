#ifndef __war3source_inavmeshhidingspot_h__
#define __war3source_inavmeshhidingspot_h__

namespace War3Source {
	/**
	 * Represents a loaded hiding spot within an area.
	 */
	class INavMeshHidingSpot {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the ID.
		 */
		virtual unsigned int GetID() = 0;

		/**
		 * Retrieve the X coordinate.
		 */
		virtual float GetX() = 0;

		/**
		 * Retrieve the Y coordinate.
		 */
		virtual float GetY() = 0;

		/**
		 * Retrieve the Z coordinate.
		 */
		virtual float GetZ() = 0;

		/**
		 * Retrieve the flags.
		 */
		virtual unsigned char GetFlags() = 0;
	};
}

#endif