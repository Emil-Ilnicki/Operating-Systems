#include <stdio.h>
#include "Q3.h"

void save_student(struct Student student);

int main(void) {
	struct Student student;

	printf("Enter student ID: ");
	scanf("%i", &student.id);
	printf("Enter student age: ");
	scanf("%i", &student.age);
	printf("Enter student's starting year: ");
	scanf("%i", &student.year);

	save_student(student);

	return 0;
}

void save_student(struct Student student) {
	FILE * file = fopen("students.txt", "a");

	fprintf(file, "%i, %i, %i\n", student.id, student.age, student.year);
	printf("%i %i %i\n", student.id, student.age, student.year);

	fclose(file);
}
