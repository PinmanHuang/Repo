#include <stddef.h>
#include "hex.h"

hex_decode(const char *inptr, size_t len, char *out) {
	unsigned int inCount, outCount, inFront, inBack;
	for( outCount = 0, inCount = 0; inCount < len; inCount += 2, ++outCount) {
		inFront = inptr[inCount] > '9' ? inptr[inCount] - 'A' + 10 : inptr[inCount] - '0';
		inBack = inptr[inCount+1] > '9' ? inptr[inCount+1] - 'A' + 10 : inptr[inCount+1] - '0';
		out[outCount] = (inFront << 4) | inBack;
	}
	return out;
}
