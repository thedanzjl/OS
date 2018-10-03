#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int N;
	printf("Enter N: ");
	scanf("%d", &N);
	int *array = malloc(N * sizeof(int));

	for (int i=0; i<N; i++) // fill with incremental values
		array[i] = i;
	printf("array:\n");
	for (int i=0; i<N; i++) // print values
		printf("%d\n", array[i]);

	free(array);

	return 0;
}