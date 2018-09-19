
#include <stdio.h>
#include <pthread.h>
#define THREAD_NUMBER 10

void do_smt(int *n) {
	printf("%d Innopolises\n", *n);
	*n = *n + 1;
}

int main() {
	pthread_t threads[THREAD_NUMBER];
	int lock = 1;

	for (int i=1; i<THREAD_NUMBER+1; i++) {
		while (lock != i) {} // waiting until previous thread will exit
		printf("Creating a thread number %d\n", i);
		pthread_create(&threads[i], NULL, do_smt, &lock);
		
	}

	pthread_exit(NULL);
	return 0;
}