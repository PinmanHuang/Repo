#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "replicate.h"

int main() {
	char instr[1000] = {0};
	int recurTimes;
	double diffTime;
	clock_t starTime, endTime, printTime;
	printf("Enter the string: ");
	scanf("%s", instr);
	printf("Enter the times you want to repeat: ");
	scanf("%d", &recurTimes);
	starTime = clock();
	replicate(instr, recurTimes);
	endTime = clock();
	diffTime = ((double)(endTime - starTime))/CLOCKS_PER_SEC;
	//	Write all string to a file
/*	FILE *fPtr;
	fPtr = fopen("outFile.txt", "w");
	if(!fPtr) {
		printf("Fails... \n");
	}
	fprintf(fPtr, buffer);
	fclose(fPtr);
*/	//	Print all string on terminal
	printf("Output: %s \n", buffer);
	printTime = clock();
	printf("\n(Recursive) run time: %f sec \n", diffTime);
	diffTime = ((double)(printTime - endTime))/CLOCKS_PER_SEC;
	printf("(Print) run time: %f sec \n", diffTime);
	printf("in: %zd byte \nout: %zd byte \n", strlen(instr), strlen(buffer));
//	free(buffer);
	return 0;
}
