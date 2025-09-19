#include <stdio.h>
#include <stdint.h> 

int main(){
	int i[4] = {1, 2, 3, 4};
	char c[4] = {'a', 'b', 'c', 'd'};
	float f[4] = {1.1, 2.2, 3.3, 4.4};
	double d[4] = {1.1, 2.2, 3.3, 4.4};
	int j;
	
	int *pi = NULL;

	pi = i;

	for(j = 1; j < 4; j++)
		printf("i + %d = %lu = %p \n", j, (unsigned long)(uintptr_t)(pi + j), (pi + j));

	printf("-----------------\n");

	char *pc = NULL;

	pc = c;

	for(j = 1; j < 4; j++)
		printf("c + %d = %lu = %p\n", j, (unsigned long)(uintptr_t)(pc + j), (pc + j));

	printf("-----------------\n");

	float *pf;
	pf = f;
	
	for(j = 1; j < 4; j++)
		printf("f + %d = %lu = %p\n", j, (unsigned long)(uintptr_t)(pf + j), (pf + j));

	printf("-----------------\n");

	double *pd;
	pd = d;

		for(j = 1; j < 4; j++)
		printf("d + %d = %lu = %p\n", j, (unsigned long)(uintptr_t)(pd + j), (pd + j));






	return 0;

}