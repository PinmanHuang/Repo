#include <string.h>
#include "hex.h"
#include <ctype.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int counter = 0, index, c;
	uint8_t out[] = "";
	char in[] = "", *infName = NULL, *outfName = NULL;
	opterr = 0;
	while((c = getopt( argc, argv, "i:o:")) != -1) {
		switch(c) {
			case 'i':
				infName = optarg;
				break;
			case 'o':
				outfName = optarg;
				break;
			case '?':
				if(optopt == 'c')
					fprintf(stderr, "Option -%c requires an argument. \n", optopt);
				else if(isprint(optopt))
					fprintf(stderr, "Unknown option '-%c'. \n", optopt);
				else
					fprintf(stderr, "Unknown option character '\\x%x'. \n", optopt);
				return 1;
			default:
				abort();
		}
	}
	FILE *fptrR = fopen(infName, "r"), *fptrW = fopen(outfName, "w");
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
	for(int i = 0; i < (counter/2); i++) {
		printf("%d: %c \n", i, out[i]);
	}
	//Save hex into file.
	fprintf(fptrW, out);
	fclose(fptrW);
}
