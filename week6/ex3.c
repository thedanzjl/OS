#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void SignalHandler(int signal_number) {
	printf("YOU SURE????\n");
}

int main() { 
	signal(SIGINT, SignalHandler);
	while(1){}
	return 0;
}