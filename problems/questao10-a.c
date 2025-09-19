#include <stdio.h>

int main(){
	int vet[] = {4, 9, 13};
	int i; 

	for(i = 0; i < 3; i++)
		printf("%d \n", *(vet + i)); /* *(vet + i) := vet[i] */
	
	return 0;
}

/* output*/

// 4
// 9
// 13

