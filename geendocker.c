#include <stdio.h>	//fprintf
#include <stdlib.h>	//EXIT_FAILURE
#include <string.h>	//strcmp
#include <unistd.h>	//execl

#define TEWEINIGARGS	"FOUT: Incorrect aantal argumenten meegekregen, de verwachte waren '/bin/login', '--', username. Maar we kregen :\n"
#define ARGINHOUD	"argv[%d]: '%s'\n"	//%d is argnr, %s is arginhoud
#define GEENSTREEPJES	"Het 1ste argument is niet '--' maar '%s'\n"
#define GEENDOCKER	"geendocker"
#define ORIGLOGIN	"/bin/ash"
#define DOCKERLOGIN	"/usr/bin/docker"
#define DOCKERLOGINARGS	"run --rm -ti --name conthoofd -v /var/run/docker.sock:/var/run/docker.sock ubuntu"

int main(int argc, char** argv) {
	if(argc < 3) {
		fprintf(stderr, TEWEINIGARGS);
		for(int i=0; i < argc; i++) {
			fprintf(stderr, ARGINHOUD, i, argv[i]);
		}
	} else if(strcmp(argv[1], "--") != 0) {
		fprintf(stderr, GEENSTREEPJES, argv[1]);
	} else if(strcmp(argv[2], GEENDOCKER) == 0) {	//TODO spaties voor en achter argv[2] wissen
		execl(ORIGLOGIN, ORIGLOGIN, (char*) NULL);
	} else {
		execl(DOCKERLOGIN, DOCKERLOGIN, DOCKERLOGINARGS, (char*) NULL);
	}
	return EXIT_FAILURE;
}
