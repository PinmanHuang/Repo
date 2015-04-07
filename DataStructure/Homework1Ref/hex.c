#include <stddef.h>
#include "hex.h"

char* hex_encode(char *inptr, size_t len, char *out) {
	unsigned int inCount, outCount, inFront, inBack;
	for( outCount = 0, inCount = 0; inCount < len; inCount += 2, ++outCount) {
		inFront = inptr[inCount] > '9' ? inptr[inCount] - 'A' + 10 : inptr[inCount] - '0';
		inBack = inptr[inCount+1] > '9' ? inptr[inCount+1] - 'A' + 10 : inptr[inCount+1] - '0';
		out[outCount] = (inFront << 4) | inBack;
	}
	return out;
}
char* hex_decode(char *inptr, size_t len, char *out) {
	unsigned int inCount, outCount, inFront, inBack;
	for( outCount = 0, inCount = 0; inCount < len; outCount++, inCount++) {
		inFront = ((inptr[inCount] >> 4) & 0x0F) | 0x30;
		inBack = (inptr[inCount] & 0X0F) | 0x30;
		out[outCount] = inFront > '9' ? inFront + 7 : inFront;
		outCount += 1;
		out[outCount] = inBack > '9' ? inBack + 7 : inBack;
	}
	return out;
}
