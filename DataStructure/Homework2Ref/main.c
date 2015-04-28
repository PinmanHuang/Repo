#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "replicate.h"

int main() {
	char instr[1000] = {0};
	size_t strLenth;
	int recurTimes;
	double diffTime;
	clock_t starTime, endTime;
	printf("Enter the string: ");
	scanf("%s", instr);
	printf("Enter the times you want to repeat: ");
	scanf("%d", &recurTimes);
	starTime = clock();
	strLenth = strlen(instr);
	printf("Output: %s \n", replicate(instr, strLenth, (size_t)recurTimes));
	endTime = clock();
	diffTime = endTime - starTime;
	printf("run time: %f \n", diffTime/CLOCKS_PER_SEC);
	printf("inLen: %zd \noutLen: %zd \n", strLenth, strlen(replicate(instr, strLenth, (size_t)recurTimes)));
	return 0;
}
