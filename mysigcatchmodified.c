#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int count=0;


void CustomSignalHandler(int sig){

	count++;
	printf("Signal %d (SIGINT) was detected! Count= %d\n",sig,count);

	if (count ==2) {

	printf("Default behaviour has been restored.\n");

		if (signal(SIGINT,SIG_DFL) == SIG_ERR) {

			perror("Error restoring default signal handler.");
			exit(1);
		}
	}
}


int main() {

	if (signal(SIGINT, CustomSignalHandler) == SIG_ERR){

		perror("Error setting custom signal handler.");

		return 1;
	}

	printf("Program is up 'n runnin'! Press Ctrl and C to send a SIGINT! \n");

	while (1){
	}

	return 0;

}
