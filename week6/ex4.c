#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void KillHandler(int signal_number) {
	printf(" YOUSURE????\n");
}

void StopHandler(int signal_number) {
	printf("YOU SURE????\n");
}

void Usr1Handler(int signal_number) {
	printf("YOU SURE????\n");
}

int main() { 
	signal(SIGKILL, KillHandler);
	signal(SIGSTOP, StopHandler);
	signal(SIGUSR1, Usr1Handler);
	while(1){}
	return 0;
}