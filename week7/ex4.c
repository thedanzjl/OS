#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void *myRealloc(void *ptr, size_t size) {
	void *result = malloc(size);
	if (ptr == NULL) {
		return malloc(size);
	}
	else if (size == 0) {
		free(ptr);
	} 

	memcpy(&result, &ptr, size);
	return result;
}

int main() {
	int *array = malloc(4);
	for (int i=0; i<4; i++)
		array[i] = i;

	for (int i=0; i<4; i++)
		printf("%d ", array[i]);
	
	printf("\n");

	array = myRealloc(array, 8); // increase size by 2

	for (int i=0; i<8; i++)
		printf("%d ", array[i]);

	printf("\n");

	return 0;
}