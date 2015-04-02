#include "hexCompressor.h"
#include <string.h>
void main() { 
	int counter = 0;
	uint8_t out[] = "";
	char in[] = "";
	FILE *fptrR = fopen("ASCII.txt", "r"), *fptrW = fopen("hex.txt", "w");
	if(fptrR == NULL)
		printf("Error while opening the file. \n");
	while((in[counter] = fgetc(fptrR)) != EOF) {
		counter++;
	}
	fclose(fptrR);
	hex_decode(in, strlen(in) ,out);
	for(int i = 0; i < (counter/2); i++) {
		printf("%d: %c \n", i, out[i]);
	}
	fprintf(fptrW, out);
	fclose(fptrW);
	return 0;
}
