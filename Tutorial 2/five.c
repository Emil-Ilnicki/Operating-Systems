#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float euc(float q, float w, float e, float r){
        float dist;
        dist = sqrt(((q-w)*(q-w)) + ((e-r)*(e-r)));
        return dist;
}



int main(){
	float result;
	float a,b,x,y = 5;
	int n = 10;

	for(int i = 0; i<10; i++){
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;	
	
		result = euc(a, b, x, y);
		printf("\n Distance is: %f\n", result);
	}

		
	return 0;
}

