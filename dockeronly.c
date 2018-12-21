#include <stdio.h>	//fprintf
#include <stdlib.h>	//EXIT_FAILURE
#include <unistd.h>	//execv

#define DOCKERLOGIN	"/usr/bin/docker"
#define DOCKERLOGINARGS	{ DOCKERLOGIN, "run", "--rm", "-ti", "--name", "conthoofd", "-v", "/var/run/docker.sock:/var/run/docker.sock", "alpine", NULL }

int main(int argc, char** argv) {
	//TODO zoveel mogelijk andere processen killen
	int returncode = execv(DOCKERLOGIN, (char *[]) DOCKERLOGINARGS);
	fprintf(stderr, "FOUT: Kon docker niet lanceren, de ontvangen returncode is %d\n", returncode);
	return EXIT_FAILURE;
}
