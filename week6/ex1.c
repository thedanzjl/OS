
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	
	int fd[2], nbytes;
    pid_t childpid;
    char string[] = "Hello, Innopolis!\n";
    char readstring[80];

    pipe(fd);
    write(fd[1], string, strlen(string)+1);
    read(fd[0], readstring, sizeof(readstring));
    printf("%s", readstring);
	return 0;
}