#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include "hex.h"
#include "base64.h"
#include "filelen.h"

int main(int argc, char **argv) {
	int counter = 0, index, c, cflag = 0, dflag = 0, flen, olen, nline = 0;
	char *infName = NULL, *outfName = NULL, *enc, *dec = NULL;

	opterr = 0;
	while((c = getopt( argc, argv, "cdhi:o:")) != -1) {	//Get option switch case.
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
			case 'h':
				printf("-c \t Compress data. \n-d \t Decompress data. \n-i \t Requiring an argument that is input file name. \n-o \t Requiring an argument that is output file name. \n");
				exit(EXIT_SUCCESS);
			case '?':
				if(optopt == 'i')
					printf(stderr, "Option -%c : required an argument \n",optopt);
				else if(optopt == 'o') 
					printf(stderr, "Option -%c : required an argument \n",optopt);
				else
					printf("Can't find -%c \n",optopt);
				return 1;
			default:
				abort();
		}
	}
	for(index = optind; index < argc; index++) {
		printf("Non-option argument %s \n",argv[index]);
	}

	FILE *fptrR = fopen(infName, "r"), *fptrW = fopen(outfName, "w");	//File read and write
	flen = GetFileLength(fptrR);
	if(cflag == 1)
		olen = 2 * flen / 3 + 1;
	if(dflag == 1)
		olen = 3 * flen / 2 + 1;
	char in[flen], out[olen];
	memset(in, 0, flen);
	memset(out, 0, olen);
	if(fptrR == NULL)
		printf("Error while opening the file. \n");
	while((in[counter] = fgetc(fptrR)) != EOF) {
		if(in[counter] == '\n') {
			nline ++;
			if(nline > 1)
				printf("Error: have %d nweline, output data will not correct. \n", nline-1);
		}
		counter++;
	}
	fclose(fptrR);
	if(cflag == 1) {
		hex_encode(in, (strlen(in)-2) ,out);
		enc = base64_encode(out, strlen(out));
		fprintf(fptrW, enc);
		fclose(fptrW);
		free(enc);
	}
	if(dflag == 1) {
		dec = base64_decode(in, strlen(in)-4);
		hex_decode(dec, (strlen(dec)), out);
		fprintf(fptrW, out);
		fclose(fptrW);
		free(dec);
	}
	else if(cflag != 1 && dflag != 1)
		printf("Error:\nIf you want to compress, you need to enter -c.\nIf you want to decompress, you need to enter -d.\n");
	return 0;
}
