
#include <stdio.h>

int main() {
	int n = 10;
	int pid = getpid();
	printf("hello from parent [%d - %d]\n", pid, n);
	fork();
	int pid = getpid();
	printf("hello from child [%d - %d]\n", pid, n);

}