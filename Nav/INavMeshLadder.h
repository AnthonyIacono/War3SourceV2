#ifndef __war3source_inavmeshladder_h__
#define __war3source_inavmeshladder_h__

#include "NavDirType.h"

namespace War3Source {
	/**
	 * Represents a loaded ladder within a navigation mesh.
	 */
	class INavMeshLadder {
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
		 * Retrieve the width in units.
		 */
		virtual float GetWidth() = 0;

		/**
		 * Retrieve the length in units.
		 */
		virtual float GetLength() = 0;

		/**
		 * Retrieve the top X coordinate.
		 */
		virtual float GetTopX() = 0;
		
		/**
		 * Retrieve the top Y coordinate.
		 */
		virtual float GetTopY() = 0;

		/**
		 * Retrieve the top Z coordinate.
		 */
		virtual float GetTopZ() = 0;

		/**
		 * Retrieve the bottom X coordinate.
		 */
		virtual float GetBottomX() = 0;

		/**
		 * Retrieve the bottom Y coordinate.
		 */
		virtual float GetBottomY() = 0;

		/**
		 * Retrieve the bottom Z coordinate.
		 */
		virtual float GetBottomZ() = 0;

		/**
		 * Retrieve the direction.
		 */
		virtual NavDirType GetDirection() = 0;
	
		/**
		 * Retrieve the top forward area ID.
		 */
		virtual unsigned int GetTopForwardAreaID() = 0;

		/**
		 * Retrieve the top left area ID.
		 */
		virtual unsigned int GetTopLeftAreaID() = 0;

		/**
		 * Retrieve the top right area ID.
		 */
		virtual unsigned int GetTopRightAreaID() = 0;

		/**
		 * Retrieve the top behind area ID.
		 */
		virtual unsigned int GetTopBehindAreaID() = 0;

		/**
		 * Retrieve the bottom area ID.
		 */
		virtual unsigned int GetBottomAreaID() = 0;
	};
}

#endif