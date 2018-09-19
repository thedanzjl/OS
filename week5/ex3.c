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
		printf("\nproducer writes 1!\n");
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
		printf("\nconsumer pops 1 and sets -1!\n");
	}
}


int main() {
	while (1) {
		pthread_t producerThread, consumerThread;
		pthread_create(&producerThread, NULL, producer, NULL);
		pthread_create(&consumerThread, NULL, consumer, NULL);
		for (int i=0; i<BUFFER_SIZE; i++) {
			printf("%d", buffer[i]);
		}
		// sleep(1);
	}
	return 0;
}

