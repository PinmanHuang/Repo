#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replicate.h"

char static *dynamicAdd;
static int nowRecurTime = 1;
char *buffer;
char* replicate(char *inData, int recurTimes) {
	if(nowRecurTime == 1) {
		buffer = malloc(strlen(inData)*(size_t)recurTimes);
		dynamicAdd = buffer;
	}
	else if(nowRecurTime == recurTimes) {
		strcpy(dynamicAdd, inData);
		return 0;
	}
	strcpy(dynamicAdd, inData);
	dynamicAdd += strlen(inData);
	nowRecurTime += 1;
	replicate(inData, recurTimes);	
}
