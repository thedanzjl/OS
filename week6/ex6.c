#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
	int fd[2];
	pipe(fd);
	pid_t childpid1 = fork();
	pid_t childpid2 = fork();

	if (childpid1 != 0 && childpid2 != 0) { // parent process
		int status;
		write(fd[1], &childpid2, sizeof(childpid2));
		printf("parent: waiting for 2nd child to be exited...\n");
		waitpid(childpid2, &status, 0);
		printf("parent: 1st child terminated 2nd child. It's over now!!!\n");

	}
	else if (childpid1 == 0) {
		read(fd[0], &childpid2, sizeof(childpid2));
		printf("1st child: recieving id of 2nd (%d)\n", childpid2);
		printf("1st child: in a few seconds send SIGSTOP to the 2nd child...\n");
		sleep(2);
		kill(childpid2, SIGSTOP);
	}
	else if (childpid2 == 0) {
		printf("2nd child: I'm in infinite loop!\n");
		while(1) {}
	}

	return 0;
}