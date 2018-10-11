#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	for (int i=0; i<10; i++) {
		struct rusage r_usage;
		void *ptr = malloc(10485760); // 10 MB
		memset(ptr, 0, 10485760);
		getrusage(RUSAGE_SELF, &r_usage);
		printf("Memory usage = %ld\n", r_usage.ru_maxrss);
		sleep(1);
	}
	// printf("%d\n", sizeof(int));
	return 0;
}