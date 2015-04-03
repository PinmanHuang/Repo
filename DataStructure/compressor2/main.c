#include "hex.h"
#include "base64.h"
#include <fcntl.h>

int main() {
	int counter = 0, i = 0;
	char out[50] = {};
	char in[100] = {};

	int fd = 0;
    char buf[1024];
    char src[1024];
    char *base64_buf;

	FILE *fptrR = fopen("ASCII.txt", "r"), *fptrW = fopen("hex.txt", "w");
	//File open failed.
	if(fptrR == NULL)
		printf("Error while opening the file. \n");
	//Scan char from file into array.
	while((in[counter] = fgetc(fptrR)) != EOF) {
		counter++;
	}
	fclose(fptrR);
	//Two ascii to one hex.
	hex_decode(in, strlen(in) ,out);
	for( i; i < (counter/2); i++) {
		printf("%d: %c \n", i, out[i]);
	}
	//Save hex into file.
	fprintf(fptrW, out);
	fclose(fptrW);

	char *enc = base64_encode(out, strlen(out));
	printf("\noriginal: %s\n", out);
	printf("\nencoded : %s\n", enc);
	free(enc);
	return 0;
}
