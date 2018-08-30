#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
	int a;
	float b;
	double c;

	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;

	printf("int max = %i", a); printf(" size = %d bytes\n", sizeof(a));
	printf("float max = %f", b); printf(" size = %d bytes\n", sizeof(b));
	printf("double max = %f", c); printf(" size = %d bytes\n", sizeof(c));

	return 0;
}