#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void GracefulTermination(){
	printf("This part simulates a graceful termination. One may include here whatever they consider is needed to be done for a termination to be gracefull.\n ");
}



void HandleSigInt(int sig) {

	printf("\nSIGINT signal detected!\n");
	GracefulTermination();
	printf("Exiting gracefully!\n");
	exit(0);
}



int main() {

	if (signal(SIGINT,HandleSigInt) == SIG_ERR) {

		perror("Error setting signal handler");
		return 1;
	}

	printf("I'm listening! Press Ctrl+C whenever your are ready!");
	fflush(stdout);

	while(1){
	}

	return 0;
}
