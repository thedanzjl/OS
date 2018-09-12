

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_COMMAND_LEN 100


int main() {
	while (1) {
		char command[MAX_COMMAND_LEN];
		printf("--->  ");
		scanf("%s", &command);
		system(command);
	}
	return 0;
}