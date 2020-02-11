#define _XOPEN_SOURCE 600

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<unistd.h>

pthread_mutex_t mutex;
pthread_barrier_t mybarrier;
double total_grade, total_bellcurve;

FILE* output;

//Thread for calculating and storing the bell curve
void* save_bellcurve(void* student)
{
  double grade = *(double*) student; //cast value as double
  pthread_mutex_trylock(&mutex);

  total_grade += grade;
  total_bellcurve += grade * 1.5;
  fprintf(output, "%f\n", grade * 1.5);

  pthread_mutex_unlock(&mutex);
  return NULL;
}

//Thread for reading grades from text file and storing them in an array
void* read_grades(void* students_ptr)
{
  double* grades = (double*)students_ptr; //cast value as double

  FILE* file = fopen("grades.txt", "r");//read from grades.txt`
  if (file == NULL)
  {
    perror("Could not open grades.txt");
  }

  for (int i = 0; i < 10; i++) //for every value in the text file, convert it to a double and store it in an array
  {
    char buf[100];
    fscanf(file, "%s", buf);
    grades[i] = atof(buf);
  }

  fclose(file);
  pthread_barrier_wait(&mybarrier);
  return NULL;
}

int main()
{
  srand(time(NULL));

  pthread_t tid[10];
  pthread_attr_t attr[10];
  double student_grade[10];

  pthread_t f_tid;
  pthread_attr_t f_attr;

  output = fopen("bellcurve.txt", "w");

  pthread_barrier_init(&mybarrier, NULL, 2); //initialize barrier for read_grades

  pthread_attr_init(&f_attr);
  pthread_create(&f_tid, &f_attr, read_grades, student_grade); //create thread to read grades

  pthread_barrier_wait(&mybarrier); // wait for thread to sync

  for (int i = 0; i < 10; i++) //Initialize 10 threads
  {
    pthread_attr_init(&attr[i]);
  }

  for (int i = 0; i < 10; i++)
  {
    pthread_create(&tid[i], &attr[i], save_bellcurve, (void*)&student_grade[i]); // create 10 threads to calculate bell curves
  }

  for (int i = 0; i < 10; i++) // join 10 previously created threads
  {
    pthread_join(tid[i], NULL);
  }

  //Print finals before and after bellcurve
  printf("BEFORE\n\nTotal Sum: %f\nTotal Average: %f\n\n", total_grade, total_grade / 10);
  printf("AFTER\n\nTotal Sum: %f\nTotal Average: %f\n", total_bellcurve, total_bellcurve / 10);

  //close files
  fclose(output);
  return 0;
}
