#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "replicate.h"

int main() {
	char instr[1000] = {0}, *outstr;
	int recurTimes;
	double diffTime;
	clock_t starTime, endTime;
	printf("Enter the string: ");
	scanf("%s", instr);
	printf("Enter the times you want to repeat: ");
	scanf("%d", &recurTimes);
	starTime = clock();
	replicate(instr, recurTimes);
	endTime = clock();
	printf("Output: %s \n", buffer);
	free(buffer);
	diffTime = ((double)(endTime - starTime))/CLOCKS_PER_SEC;
//	diffTime = diffTime/CLOCKS_PER_SEC;
	printf("run time: %f sec \n", diffTime);
//	printf("inLen: %zd \noutLen: %zd \n", strLenth, strlen(replicate(instr, strLenth, (size_t)recurTimes)));
	return 0;
}
