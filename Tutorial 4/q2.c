#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef void* Student;

struct student_t {
    float grade;
};

void printStudent(Student _student) {
    struct student_t* student = (struct student_t*) _student;
    printf("%f\n", student->grade);
}

Student createStudent(float grade) {
    struct student_t* student;
    student = (struct student_t*)malloc(sizeof(struct student_t));
    student->grade = grade;
    return (Student) student;
}

void* bellcurve(Student _student) {
    printStudent(_student);
    return NULL;
}

int main() {
    int numOfStudents = 5;

    pthread_t *threadArray;
    Student* studentArray;

    threadArray = (pthread_t*)malloc(numOfStudents * sizeof(pthread_t));
    studentArray = (Student*)malloc(numOfStudents * sizeof(struct student_t));

    for (int i = 0; i < numOfStudents; i++) {
        float grade;
        printf("Enter grade for student #%d: ", i + 1);
        scanf("%f", &grade);
        studentArray[i] = createStudent(grade);
    }

    for (int i = 0; i < numOfStudents; i++) {
        void* stud = (void*)studentArray[i];
        pthread_create(&threadArray[i], NULL, bellcurve, stud);
    }

    for (int i = 0; i < numOfStudents; i++) {
        pthread_join(threadArray[i], NULL);
    }

    return 0;
}
