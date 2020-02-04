#include <stdio.h>

int main(void) {
	for (int index = 1; index <= 10; index++) {
		if (index % 2 == 0) {
			printf("%i EVEN\n", index);
		}
		else {
			printf("%d ODD\n", index);
		}
	}

	return 0;
}
