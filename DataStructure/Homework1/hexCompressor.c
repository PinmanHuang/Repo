#include "hexCompressor.h"
void compressToHex(char *iptr1, char *iptr2, char *optr) {
	toHex(&iptr1);
	toHex(&iptr2);
	*iptr1 = *iptr1 & (*iptr1 << 8);
	printf("hexC1: %c \n", *iptr1);
	*iptr2 = *iptr2 & (*iptr2 << 8); 
	printf("hexC2: %c \n", *iptr2);
	*optr = (*iptr1 << 4) | *iptr2;
}
void toHex(char *iptr) {
	if('A'<= *iptr <= 'Z'|| 'a' <= *iptr <= 'z') {
		*iptr += 9; 
	}
}
