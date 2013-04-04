#include "Utils.h"

namespace War3Source {
	void StrCopy(char *dest, unsigned int destSize, const char *src) {
		for(unsigned int i = 0; i < destSize; i++) {
			if(src[i] == '\0') {
				dest[i] = '\0';
				break;
			}
			dest[i] = src[i];
		}
	}
}