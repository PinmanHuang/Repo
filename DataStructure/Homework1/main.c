#include "hexCompressor.h"
void main() {
	char asciiInput[100], outputStack[50], test1, test2, testresult;
	asciiInput[0] = '6';
	asciiInput[1] = '5';
	test1 = asciiInput[0] << 4;
	test2 = asciiInput[1];
	testresult = test1 | test2;
	printf("Test1: %c \n", test1);
	printf("Test2: %c \n", test2);
	printf("testresult: %c \n", testresult);
	compressToHex(&asciiInput[0], &asciiInput[1], &outputStack[0]);
	printf("Hex digital: %c \n", outputStack);
}
