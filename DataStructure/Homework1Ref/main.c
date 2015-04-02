#include <ctype.h>
#include "hex.h"
#include <unistd.h>
#include <getopt.h>
int main(int argc, char **argv) {
	int counter = 0, index, c;
	uint8_t out[50] = {0};
	char in[100] = {0}, *infName = NULL, *outfName = NULL;
	
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
	printf("in: %s, out: %s \n", infName, outfName);
	for(index = optind; index < argc; index++) {
		printf("Non-option argument %s \n",argv[index]);
	}
	FILE *fptrR = fopen(infName, "r"), *fptrW = fopen(outfName, "w");
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
