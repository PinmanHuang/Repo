#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "replicate.h"

int main() {
	char instr[20] = {0};
	size_t strLenth;
	int recurTimes;
	printf("Enter the string: ");
	scanf("%s", instr);
	printf("Enter the times you want to repeat: ");
	scanf("%d", &recurTimes);
	strLenth = strlen(instr);
	printf("Output: %s \n", replicate(instr, strLenth, (size_t)recurTimes));
	printf("inLen: %zd \noutLen: %zd \n", strLenth, strlen(replicate(instr, strLenth, (size_t)recurTimes)));
	return 0;
}
