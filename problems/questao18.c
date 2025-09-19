#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

/*initv: recebe um endereço de ponteiro e um tamanho*/
void initv(int **v, int l){
	int i;

	for(i = 0; i < l; i++)
		(*v)[i] = i*10; /* atribui ao vetor declarado em main, começando do zero, os 10 primeiros multiplos de 10. */

}


/*printv: recebe o endereço do primerio elemento de um vetor e um inteiro */
void printv(int *v, int l){
	int i;

	for(i = 0; i < l; i++)
		printf("v[%d] = %d ", i, v[i]);
	putchar('\n');
}


int main(){
	int *v = malloc(MAXSIZE * sizeof(int)); /* aloca dinamicamente 40 bytes de memória para armazenar até 10 ints*/
	void (*pf)(int*, int); /* declaração de pontero para função */

	if(v == NULL) /* verifica se alocação dinâmica foi de fato realizada */
		return 1;

	initv(&v, MAXSIZE); /* inicializa v com MAXSIZE valores */
	
	pf = printv; /* atribui a pf o endereço da função printv */
 	pf(v, MAXSIZE); /* usa pf para chamar implicitamente printv */

	free(v); /* libera a memória alocada para v para evitar memory leak */


	return 0;
}

/*
ponteiro para função é basicamente um ponteiro que vai armazenar o endereço de uma função
para que possamos de forma implicita realizar chamadas da função referenciada pelo ponteiro.
*/