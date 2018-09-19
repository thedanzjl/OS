#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 4

int buffer[BUFFER_SIZE];
int N = 0; // number of items in buffer
bool producerSleep = false;
bool consumerSleep = false;


void producer() {
	//puts an item in the buffer
	if (producerSleep == false) {
		if (N == BUFFER_SIZE) {
			producerSleep = true;
			return;
		}
		buffer[N] = 1;
		N++;
		consumerSleep = false;
		// printf("\nproducer writes 1!\n");
	}
}


void consumer() {
	//pops an item from the buffer
	if (consumerSleep == false) {
		if (N == 0) {
			consumerSleep = true;
			return;
		}
		buffer[N] = -1;
		N--;
		producerSleep = false;
		// printf("\nconsumer pops 1 and sets -1!\n");
	}
}

int race1, race2;

int main() {
	while (1) {
		pthread_t producerThread, consumerThread;
		race1 = pthread_create(&producerThread, NULL, producer, NULL);
		race2 = pthread_create(&consumerThread, NULL, consumer, NULL);
		printf("race1=%d, race2=%d\n", race1, race2);
		if (race1 != 0 || race2 != 0) { 
			printf("fatal race condition occured!!\n");
			return 0;
		}
		for (int i=0; i<BUFFER_SIZE; i++) {
			printf("%d", buffer[i]);
		}
	}
	return 0;
}

