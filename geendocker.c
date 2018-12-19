#include <stdio.h>	//fprintf
#include <stdlib.h>	//EXIT_FAILURE
#include <string.h>	//strcmp
#include <unistd.h>	//execl

#define TEWEINIGARGS	"FOUT: Incorrect aantal argumenten meegekregen, de verwachte waren '/bin/login', '--', username. Maar we kregen :\n"
#define ARGINHOUD	"argv[%d]: '%s'\n"	//%d is argnr, %s is arginhoud
#define GEENSTREEPJES	"Het 1ste argument is niet '--' maar '%s'\n"
#define GEENDOCKER	"geendocker"
#define ORIGINELELOGIN	"/bin/login_ORIG"
#define DOCKERLOGIN	"/bin/ash"

int main(int argc, char** argv) {
	if(argc < 3) {
		fprintf(stderr, TEWEINIGARGS);
		for(int i=0; i < argc; i++) {
			fprintf(stderr, ARGINHOUD, i, argv[i]);
		}
	} else if(strcmp(argv[1], "--") != 0) {
		fprintf(stderr, GEENSTREEPJES, argv[1]);
	} else if(strcmp(argv[2], GEENDOCKER) != 0) {
		execl(ORIGINELELOGIN, ORIGINELELOGIN, (char*) NULL);
	} else {
		execl(DOCKERLOGIN, DOCKERLOGIN, (char*) NULL);
	}
	return EXIT_FAILURE;
}
