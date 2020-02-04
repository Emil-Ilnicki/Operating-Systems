#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *tutFile;
	tutFile = fopen("question2.txt", "r");

	int arr[11];
	int i;

	int(tutFile == NULL){
		printf("Error\n");
		exit(0);
	}
	
	for(i=0; i<10;i++){
		fscanf(tutFile, "%d,", &arr[i]);
	}

	printf("numbers are: ");

	for(i=0; i<10; i++){
		printf(" %d ", arr[i]);
	}

	printf("\n");
	fclose(tutFile);

	return 0;
}