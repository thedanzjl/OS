#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *r = fopen("/dev/random", "r");
	FILE *dst = fopen("ex1.txt", "w+");
	char a[20];
	fgets(a, 20, r);
	fputs(a, dst);
	fclose(r);
	fclose(dst);
	return 0;
}