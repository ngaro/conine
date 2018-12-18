#include <stdio.h>	//fprintf
#include <unistd.h>	//execl
#include <stdlib.h>	//EXIT_FAILURE
//#include <string.h>	//strcmp

//#define	GEENDOCKER	"geendocker"
#define GEENDOCKERSHELL	"/bin/ash"
#define TEWEINIGARGS	"FOUT: Incorrect aantal argumenten meegekregen, de verwachte waren '/bin/login', '--', username. Maar we kregen :\n"
#define GEENSTREEPJES	"Het 1ste argument is niet '--' maar '%s'\n"
#define ARGINHOUD	"argv[%d]: '%s'\n"	//%d is argnr, %s is arginhoud

int main(int argc, char** argv) {
	if(argc < 3) {
		fprintf(stderr, TEWEINIGARGS);
		for(int i=0; i < argc; i++) {
			fprintf(stderr, ARGINHOUD, i, argv[i]);
		}
		return EXIT_FAILURE;
	}
	if(strcmp(argv[1],"--") != 0) {
		fprintf(stderr, GEENSTREEPJES);
		return EXIT_FAILURE;
	}
	execl(GEENDOCKERSHELL, GEENDOCKERSHELL, (char*) NULL);
	return EXIT_FAILURE;
}
