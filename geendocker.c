#include <stdio.h>	//fprintf
#include <stdlib.h>	//EXIT_FAILURE
#include <string.h>	//strcmp
#include <unistd.h>	//execl

#define TEWEINIGARGS	"FOUT: Incorrect aantal argumenten meegekregen, de verwachte waren '/bin/login', '--', username. Maar we kregen :\n"
#define ARGINHOUD	"argv[%d]: '%s'\n"	//%d is argnr, %s is arginhoud
#define GEENSTREEPJES	"Het 1ste argument is niet '--' maar '%s'\n"
#define GEENDOCKER	"geendocker"
#define ORIGLOGIN	"/bin/ash"
#define ORIGLOGINARGS	{ ORIGLOGIN, NULL }
#define DOCKERLOGIN	"/usr/bin/docker"
#define DOCKERLOGINARGS	{ DOCKERLOGIN, "run", "--rm", "-ti", "--name", "conthoofd", "-v", "/var/run/docker.sock:/var/run/docker.sock", "ubuntu", NULL }

int main(int argc, char** argv) {
	if(argc < 3) {
		fprintf(stderr, TEWEINIGARGS);
		for(int i=0; i < argc; i++) {
			fprintf(stderr, ARGINHOUD, i, argv[i]);
		}
	} else if(strcmp(argv[1], "--") != 0) {
		fprintf(stderr, GEENSTREEPJES, argv[1]);
	} else if(strcmp(argv[2], GEENDOCKER) == 0) {	//TODO user en wachtwoord vragen en hem laten inloggen met de juiste env
		execv(ORIGLOGIN, (char *[]) ORIGLOGINARGS);
	} else {	//TODO wachtwoord vragen, checken of de user in de docker group zit en de container als hem opstarten, root mag alles
		execv(DOCKERLOGIN, (char *[]) DOCKERLOGINARGS);
	}
	return EXIT_FAILURE;
}
