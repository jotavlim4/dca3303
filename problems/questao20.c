#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compf(const void *a, const void *b){
	float fa = *(const float *) a;   /* primeiro converte 'a' para 'const float *', depois atribui a 'fa' o conteudo apontado por 'a' */
	float fb = *(const float *) b; /* primeiro converte 'b' para 'const float *', depois atribui a 'fb' o conteudo apontado por 'b' */

	if(fa < fb) /* 'fa' vem antes de 'fb' */
		return -1;
	if(fa > fb) /* 'fa' vem depois de 'fb' */
		return 1;
	return 0; /* são iguais */

}


/* recebe o endereço do primeiro elemento apontado pelo vetor v e um inteiro*/
void initv(float *v, int l){
	int i;

	for(i = 0; i < l; i++)
		scanf("%f", (v + i)); /* grava no endereço (v + i) o float lido do teclado, (v + i) := &v[i] */
}

/* recebe o endereço do primeiro elemento apontado pelo vetor v e um inteiro*/
void printv(float *v, int l){
	int i;

	for(i = 0; i < l; i++)
		printf("%.2f ", *(v + i)); /* *(v + i) := v[i] */
	putchar('\n');
}

int main(){
	int n;
	
	scanf("%d", &n); /* le um inteiro do teclado e atribui ele a n*/
	if(n <= 0) /* verifica se n é um valor válido para a alocação de memória */
		return 1;

	float *v = malloc(n * sizeof(float)); /* malloc aloca memóra para 'n' floats e faz 'v' apontar para o primeiro bloco */
	if(v == NULL) /* verifica se a alocação foi feita com sucesso */
		return 1;
	
	initv(v, n); /* inicializa v com n valores que serão lidos do teclado */
	qsort(v, n, sizeof(float), compf); /* ordena o vetor chamando 'qsort', que recebe: o endereço do primeiro elemento, o número de itens, o tamanho em bytes de cada item e a função de comparação*/
	printv(v, n); /* exibe os valores de v após a ordenação */

	free(v); /* libera a memóra alocada para evitar memory leak */

	return 0;
}