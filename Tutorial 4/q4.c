#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double totalGrade;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *class_total(double *grade){
    pthread_mutex_lock(&mutex);
    totalGrade += *((double*)grade);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
    return 0;
}

int main(void){

    double *arg;
    double grade;
    pthread_t *marks;

    marks = (pthread_t*)malloc(10*sizeof(pthread_t));

    for (int i = 0; i < 10; i++){
        printf("Enter the student grade\n");
        scanf("%lf", &grade);
        *arg = grade;
        pthread_create(&marks[i], NULL, class_total, arg);
        pthread_join(marks[i],NULL);
    }

    
    printf("Total Grade: %lf\n", totalGrade);

}
