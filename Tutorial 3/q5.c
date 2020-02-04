#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct grades {
    int student_id;
    int mark;
};

void grade_students(struct grades *studentGrades, int num_students);
int main (void){
    char *professor = calloc(256,sizeof(char));
    struct grades *studentGrades;

    printf("Please enter your name\n");
    scanf("%s", professor);

    printf("Please enter the number of students\n");
    int amount = 0;
    scanf("%d", &amount);

    studentGrades = malloc(amount*sizeof(int));

    for (int i = 0; i < amount; ++i){
        printf("Enter Student ID and Mark\n");
        scanf("%d%d", &(studentGrades+i)->student_id, &(studentGrades+i)->mark);
    }

    grade_students(studentGrades, amount);

}

void grade_students(struct grades *studentGrades, int num_students){
    FILE *fp = fopen("grades.txt","w");
    int sum;
    int average;
    int sd;
    int varsum;

    for (int n=0; n < num_students; ++n){
        sum = sum + studentGrades[n].mark;
        fprintf(fp, "Student #%d mark = %d \n", (studentGrades+n)->student_id, (studentGrades+n)->mark);
    }
    average = sum/num_students;

    for (int n=0; n<num_students; ++n){
        varsum = varsum + pow((studentGrades[n].mark - average),2);
    }

    sd = sqrt (varsum/num_students);
    fprintf(fp, " average = %d , standard deviation = %d.", average, sd);
    fclose(fp);
}
