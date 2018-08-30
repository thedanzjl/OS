#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a; // get value stored in address a
	*a = *b; // put value stored in b into a
	*b = temp; // put temp value into b
}

int main() {
	
	int a, b;
	printf("Enter two integeres: ");
	scanf("%d %d", &a, &b);

	swap(&a, &b); // pass a and b by reference

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	return 0;
}