#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEN 100

int main() {
	
	char string[MAX_STRING_LEN] = {0};

	printf("Enter any string to get reverse one: ");
	gets(string);
	printf("Reversed one is: ");

	for (int i=MAX_STRING_LEN-1; i>=0; i--) {
		printf("%c", string[i]);
	}
	printf("\n");

	return 0;
}