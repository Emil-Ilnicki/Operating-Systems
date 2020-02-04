#include <stdio.h>

int main(void) {
	char firstName[100];
	printf("Enter your first name: ");
	scanf("%s", firstName);

	int age;
	printf("Enter your age: ");
	scanf("%i", &age);

	double height;
	printf("Enter your height: ");
	scanf("%lf", &height);

	printf("***********************************************\n");
	printf("Your first-name is: %s\n", firstName);
	printf("Your age is: %i\n", age);
	printf("Your height is: %.3f\n", height);

	return 0;
}
