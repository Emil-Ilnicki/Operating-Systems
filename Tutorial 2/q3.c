#include <stdio.h>

int main (){
	char s[20] = "Hello World\0";
	int i = 0;

	while(1){
		if(s[i] != '\0'){
			printf("%c", s[i]);
		}
		else{
			printf("\n");
			break;
		}
	i++;
	}
}
