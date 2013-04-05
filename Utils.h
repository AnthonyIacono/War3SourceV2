#ifndef __war3source_utils_h__
#define __war3source_utils_h__


namespace War3Source {
	void StrCopy(char *dest, unsigned int destSize, const char *src);
	size_t StrFormat(char *buffer, size_t maxlength, char const *fmt, ...);
}

#endif