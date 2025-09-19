#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/* assinatura de funções */
void my_sort(int *b, int nitens, int (*comp)(const void *, const void *));
void swap(int *a, int *b);
int compi(const void *a, const void *b);
void printv(int *v, int l);
void initv(int *v1, int *v2, int l);

int main(){
	int n;
	clock_t start, end;
	double time_cpu;
	long ultime;

	/* referencia: luiz damas, linguagem c, pág. 148, cap. 6 */
	time(&ultime);
	srand((unsigned) ultime);
	
	scanf("%d", &n);
	if(n <= 0)
		return 1;

	int *numbers1 = malloc(n * sizeof(int));
	int *numbers2 = malloc(n * sizeof(int));
	if(numbers1 == NULL || numbers2 == NULL)
		return 1;

	initv(numbers1, numbers2, n);
	
	/* tempo de execução de my_sort */
	start = clock();
	my_sort(numbers1, n, compi);
	end = clock();
	time_cpu = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("tempo de execução de 'my_sort': %f sec\n", time_cpu);

	/* tempo de execução de qort */
	start = clock();
	qsort(numbers2, n, sizeof(int), compi);
	end = clock();
	time_cpu = (double)(end - start) / CLOCKS_PER_SEC;
	printf("tempo de execução de 'qsort': %f sec\n", time_cpu);

	printf("vetores ondernados:\n");
	printv(numbers1, n);
	printv(numbers2, n);

	return 0;
}

/* ordena em sequencia, elemento por elemento*/
void my_sort(int *b, int nitens, int (*comp)(const void *, const void *)){
	int i, j, (*pf)(const void *, const void *);

	pf = comp;
	for(i = 0; i < nitens; i++)
		for(j = i + 1; j < nitens; j++)
			if(pf(&b[j], &b[i]) == -1)
				swap(&b[j], &b[i]);	
}

void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int compi(const void *a, const void *b){
	int fa = *(const int *)a;
	int fb = *(const int *)b;

	if(fa < fb) return -1;
	if(fa > fb) return 1;
	return 0; 
}

void printv(int *v, int l){
	int i;

	for(i = 0; i < l; i++)
		printf("%d ", *(v + i)); /* *(v + i) := v[i] */
	putchar('\n');
}

void initv(int *v1, int *v2, int l){
	int i;
	for(i = 0; i < l; i++)
		v1[i] = v2[i] = rand() % l;
}