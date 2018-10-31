#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	char* target_string = "This is a nice day";
	int file = open("ex1.txt", O_RDWR);
	struct stat mystat = {};
	if (fstat(file, &mystat)) {
		perror("fstat"); 
		exit(1); 
	}
	off_t file_size = mystat.st_size;
	char* address = mmap(NULL, file_size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
	for (int i=0; i<strlen(target_string); i++) {
		address[i] = target_string[i];
	}
	printf("%s\n", (char*)address);

	return 0;

}