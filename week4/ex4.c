
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAX_COMMAND_LEN 100


int main() {
	while (1) {
		char command[MAX_COMMAND_LEN];
		char bckcommand[MAX_COMMAND_LEN + 1];
		gets(command);
		strcpy(bckcommand, command);
		bckcommand[strlen(command)] = ' ';
		bckcommand[strlen(command)+1] = '&';
		system(bckcommand);
	}
	return 0;
}
