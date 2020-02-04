#include <stdlib.h>
#include <stdio.h>

int main(){
	char *namePtr;
	int *students_ids;
	int *grades;
	namePtr = calloc(256,sizeof(char));
	printf("Please enter your name\n");
	scanf("%s", namePtr);

	printf("Please enter the number of students\n");
	int amount = 0;
	scanf("%d", &amount);

	students_ids = (int*) malloc(amount*sizeof(int));
	grades = (int*) malloc(amount*sizeof(int));

	free(namePtr);
	free(students_ids);
	free(grades);

}
