#include <stdio.h>

int GetFileLength(FILE *fileName) {
	unsigned long pos = ftell(fileName);
	unsigned long len = 0;
	fseek(fileName, 0L, SEEK_END);
	len = ftell(fileName);
	fseek(fileName, pos, SEEK_SET);
	return len;
}
