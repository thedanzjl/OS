#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main() {
	pid_t childpid = fork();
	if (childpid != 0) { // parent process
		sleep(10);
		kill(childpid, SIGTERM); // terminate child process
	}
	else { // child process
		while (1) {
			printf("I'm alive\n");
			sleep(1);
		}
	}
	return 0;
}