#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replicate(char *indata, size_t strLength, size_t recurTimes) {
	char *strBuffer, *strBuffer_pre;
	if(recurTimes == 0) {
		strBuffer = malloc(1);
		strBuffer[0] = '\0';
		return strBuffer;
	}
	strBuffer = (char *)malloc(strLength*recurTimes+1);
	strBuffer_pre = replicate(indata, strLength, recurTimes-1);

	strcpy(strBuffer, strBuffer_pre);
	strcpy(strBuffer+(recurTimes-1)*strLength, indata);
	free(strBuffer_pre);
	return strBuffer;
}
