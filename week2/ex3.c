#include <stdio.h>
#include <string.h>

int main() {
	
	int n;
	printf("Enter number in order to observe a triangle: ");
	scanf("%d", &n);
	printf("\n");
	int max_width = 2 * n;

	for (int height=1; height<n+1; height++) {
		int n_stars = height * 2 - 1;
		for (int width=0; width<max_width; width++) {
			char elem; // either space or star
			int n_spaces = (max_width - n_stars) / 2;
			if (width <= n_spaces || width >= (max_width - n_spaces)) {
				elem = ' ';
			}
			else {
				elem = '*';
			}

			printf("%c", elem);
		}
		printf("\n");
	}

	return 0;
}