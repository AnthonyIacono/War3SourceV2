#include "Utils.h"
#include <stdarg.h>
#include <iostream>

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

	size_t StrFormat(char *buffer, size_t maxlength, char const *fmt, ...) {
		va_list ap;
		va_start(ap, fmt);
		size_t len = vsnprintf(buffer, maxlength, fmt, ap);
		va_end(ap);

		if(len >= maxlength) {
			buffer[maxlength - 1] = '\0';
			return (maxlength - 1);
		}

		return len;
	}
}