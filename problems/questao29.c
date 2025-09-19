#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define STATE 2

unsigned int **p_to_p(int nl, int nc);
void init_m(unsigned int **m, int nl, int nc);
void init_random();
unsigned long encode_matrix(unsigned int **m, int nl, int nc);
void print_m(unsigned int **m, int nl, int nc);
void print_bin(unsigned long number);

int main(){
	unsigned int **m = NULL;
	unsigned long encoded_matrix;

	init_random();

	m = p_to_p(SIZE, SIZE);

	init_m(m, SIZE, SIZE);

	printf("Matriz a ser codificada: \n\n");
	print_m(m, SIZE, SIZE);
	putchar('\n');

	printf("--------------------------------\n");

	encoded_matrix = encode_matrix(m, SIZE, SIZE);
	printf("Número inteiro correspodente a matriz codificada = %lu\n", encoded_matrix);

	printf("Em binário: ");
	print_bin(encoded_matrix);

	free(m[0]);
	free(m);
	return 0;
}

unsigned int **p_to_p(int nl, int nc){
	int i;
	unsigned int **m = malloc(nl * sizeof(unsigned int *));

	if(m == NULL)
		return NULL;

	m[0] = malloc(nl * nc * sizeof(unsigned int));
	if(m[0] == NULL){
		free(m);
		return NULL;
	}


	for(i = 1; i < nl; i++)
		m[i] = m[i - 1] + nc;

	return m;
}

void init_random(){
    long last_t;

    time(&last_t);
    srand((unsigned) last_t);
}

void init_m(unsigned int **m, int nl, int nc){
    int i, j;

    for(i = 0; i < nl; i++)
        for(j = 0; j < nc; j++)
            m[i][j] = rand() % STATE;
}

void print_m(unsigned int **m, int nl, int nc){
    int i, j;

    for(i = 0; i < nl; i++){
        putchar('[');
        for(j = 0; j < nc; j++)
           j == nc - 1 ? printf("%2d", m[i][j]) : printf("%2d ", m[i][j]);
        putchar(']');
        putchar('\n');
    }
}

unsigned long encode_matrix(unsigned int **m, int nl, int nc){
	unsigned long encoded = 0; /* (00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000)  */
	int i, j;
	int current_pos;

	current_pos = 0;
	for(i = 0; i < nl; i++){
		for(j = 0; j < nc; j++){
			if(m[i][j] == 1){
				current_pos = (nc * nl - 1) - (i * nc + j);   /* (nc * nl - 1) a posicao mais significa da matriz (63...0) */
				encoded |= (1UL << current_pos);		      /* (i * nc + j) corresponde ao que já percorremos */
			}										          /* a diferença desses dois valores corresponde a posição atual do 1 localizado. */
		}											          /* usamos essa informação para deslocar o bit 1 de 1UL 'pos' vezes para esquerda */
	}													      /* após isso basta fazermos:   */
	return encoded;											  /* (10100010 00000000) or (00000000 01000000) = (10100010 01000000)*/
}	                                                          /* supondo que (10100010 00000000) é encoded */
				                                              /* gravando o bit 1 na posição mais significativa correspondente de encoded */


void print_bin(unsigned long number) {
    for (int i = 63; i >= 0; i--) {
        putchar((number & (1UL << i)) ? '1' : '0');  /* desloca o bit 1 de 1ULL i posicoes para esquerda */
        if (i % 8 == 0) putchar(' ');                 /* e compara com o bit de number na mesma posicao. */
    }
    putchar('\n');
}


/* tenho que dar um jeito de escrever o padrão de bits da matriz, nesse número 'encoded' */
/* provavelmente preciso usar bit a bit*/
/* mas como mudar esses bits? */
/* e como fazer isso da esqueda para a direita? */

/* como codificar uma matriz de uns e zeros naquele número grandão?? */
/* posso usar OR bit a bit pois (00000000) | (alguma coisa em binário) = (alguma coisa em binário) */
/* então preciso pegar cada uma das entradas significativas da matriz (1's) e gravar essa informação */
/* nos bits do long unsigned */

/* como fazer isso da direita para esquerda? */

/* https://en.wikipedia.org/wiki/Bit_array */
/* https://discussions.unity.com/t/serializing-a-2d-array/166060 */
/* https://stackoverflow.com/questions/6051614/compressing-a-binary-matrix */
