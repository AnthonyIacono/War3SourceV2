#ifndef __war3source_iskill_h__
#define __war3source_iskill_h__

namespace War3Source {
	/**
	 * Represents one character skill.
	 */
	class ISkill {
	public:
		/**
		 * Destroy the instance.
		 */
		virtual void Destroy() = 0;

		/**
		 * Retrieve the name of the skill.
		 */
		virtual const char *GetName() = 0;

		/**
		 * Retrieve the class of the skill.
		 */
		virtual const char *GetClass() = 0;

		/**
		 * Retrieve the current level of the skill.
		 */
		virtual int GetLevel() = 0;
	};
}

#endif