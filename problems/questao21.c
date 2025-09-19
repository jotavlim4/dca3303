#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* assinatura de funções */
void my_sort(int *b, int nitens, int (*comp)(const int *, const int *));
void swap(int *a, int *b);
int compi(const int *a, const int *b);
void printv(int *v, int l);
void initv(int *v, int l);

int main(){
	int n;
	
	scanf("%d", &n);
	if(n <= 0)
		return 1;

	int *numbers = malloc(n * sizeof(int));
	if(numbers == NULL)
		return 1;

	initv(numbers, n);
	my_sort(numbers, n, compi);
	printv(numbers, n);

	return 0;
}

/* ordena em sequencia, elemento por elemento*/
void my_sort(int *b, int nitens, int (*comp)(const int *, const int *)){
	int i, j, (*pf)(const int *, const int *);

	pf = comp;
	for(i = 0; i < nitens; i++)
		for(j = i + 1; j < nitens; j++)
			if(pf(&b[j], &b[i]) == 1)
				swap(&b[j], &b[i]);
		
}

void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int compi(const int *a, const int *b){
	int fa = *a;
	int fb = *b;

	if(fa < fb) return 1;
	if(fa > fb) return -1;
	return 0; 
}

void printv(int *v, int l){
	int i;

	for(i = 0; i < l; i++)
		printf("%d ", *(v + i)); /* *(v + i) := v[i] */
	putchar('\n');
}

void initv(int *v, int l){
	int i;

	for(i = 0; i < l; i++){
		scanf("%d", (v + i)); /* grava no endereço (v + i) o float lido do teclado, (v + i) := &v[i] */
		getchar();
	}
}