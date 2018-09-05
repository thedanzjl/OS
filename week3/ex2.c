#include <stdio.h> 


void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}


void bubble_sort(int *array, int len) {

	for (int i=len-2; i>=0; i--) {
		for (int j=0; j<=i; j++) {
			if (*(array+j) > *(array+j+1)) {
				swap(array+j, array+j+1);
			}
		}
	}

}



int main() {

	int a[5] = {5, 4, 3, 2, 1};
	bubble_sort(&a, 5);

	// printing array
	for (int i=0; i<5; i++)
		printf("%d\n", a[i]);

	return 0;
}



