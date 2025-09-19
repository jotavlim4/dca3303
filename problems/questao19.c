#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b){
	float temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


void initv(float *v, int l){
	int i;

	for(i = 0; i < l; i++)
		scanf("%f", &v[i]);
}

void bsort(float *v, int l){
	int i, j;

	for(i = 0; i < l; i++)
		for(j = 0; j < l - i - 1; j++)
			if(v[j] > v[j + 1]){
				swap(&v[j], &v[j+1]);
			}
}

void printv(float *v, int l){
	int i;

	for(i = 0; i < l; i++)
		printf("%.2f ", v[i]);
	putchar('\n');
}

int main(){
	int n;
	
	scanf("%d", &n); if(n <= 0) return 1;

	float *v = malloc(n * sizeof(float)); if(v == NULL) return 1;
	
	initv(v, n);
	bsort(v, n);
	printv(v, n);

	free(v);

	return 0;
}