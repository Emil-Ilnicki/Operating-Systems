#include <stdio.h>
#include <float.h>

int main() {
	double data[5] = {1.2, 5.5, 2.1, 3.3, 3.3};

	for (int i = 0; i < 5; i++){
		if (i == 0){
			printf("%f is greater than 0\n", data[i]);
		}
		else{
			if (data[i] > data[i-1]){
				printf("%f is greater than %f\n", data[i], data[i-1]);
			}
			else if(data[i] < data[i-1]){
				printf("%f is less than %f\n", data[i], data[i-1]);
			}
			else {
				printf("%f is equal to %f\n", data[i], data[i-1]);
			}
		}
	}

}
