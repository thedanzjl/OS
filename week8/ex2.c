
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	for (int i=0; i<10; i++) {
		void *ptr = malloc(10485760); // 10 MB
		memset(ptr, 0, 10485760);
		sleep(1);
	}
	// printf("%d\n", sizeof(int));
	return 0;
}