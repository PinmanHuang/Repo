#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include "hex.h"
#include "base64.h"

int main(int argc, char **argv) {
	int counter = 0, index, c, cflag = 0, dflag = 0;
	char in[100] = {0}, out[50] = {0}, *infName = NULL, *outfName = NULL, *enc, *dec = NULL;

	opterr = 0;
	while((c = getopt( argc, argv, "cdi:o:")) != -1) {	//Get option switch case.
		switch(c) {
			case 'c':
				cflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
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

	FILE *fptrR = fopen(infName, "r"), *fptrW = fopen(outfName, "w");	//File read and write
	if(fptrR == NULL)
		printf("Error while opening the file. \n");
	while((in[counter] = fgetc(fptrR)) != EOF)
		counter++;
	fclose(fptrR);
	if(cflag == 1) {
		hex_encode(in, (strlen(in)-2) ,out);
		enc = base64_encode(out, strlen(out));
		fprintf(fptrW, enc);
		fclose(fptrW);
		free(enc);
	}
	if(dflag == 1) {
		dec = base64_decode(in, strlen(in));
		hex_decode(dec, (strlen(dec)), out);
		printf("out: %s \n", out);
		fprintf(fptrW, out);
		fclose(fptrW);
		free(dec);
	}
	return 0;
}
