#include <stdio.h>

int main(){
	int vec[] = {1, 2, 3, 4, 5 , 6};
	int *pv = NULL;

	pv = vec;

	printf("terceiro elemento de vec = %d\n", vec[2]);
	printf("terceiro elemento de vec = %d\n", *(pv + 2));

}