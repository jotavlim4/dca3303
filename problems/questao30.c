#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

/* https://stackoverflow.com/questions/2306172/malloc-a-3-dimensional-array-in-c */

/* assinatura de funções */
int ***alloc_3d_arr(size_t dim1, size_t dim2, size_t dim3);
void free_3d_arr(int ***arr);
void init_3d_arr(int ***arr, int xlen, int ylen, int zlen);
void init_random();
void choose_plane(int ***arr, int xlen, int ylen, int zlen);
void print_plane(size_t choise, char ch_choise, int ***arr, int xlen, int ylen, int zlen);
void action(int ***arr, int xlen, int ylen, int zlen);
void change_value(int ***arr, int xlen, int ylen, int zlen);
int dim(int *xlen, int *ylen, int *zlen);

int main(){
	int xlen, ylen, zlen;
	int ***arr_3d = NULL;
	
	init_random();

	if(dim(&xlen, &ylen, &zlen)){

		arr_3d = alloc_3d_arr(xlen, ylen, zlen);

		init_3d_arr(arr_3d, xlen, ylen, zlen);

		action(arr_3d, xlen, ylen, zlen);

		/* desaloca memória no heap */
		free_3d_arr(arr_3d);
	}
	
	return 0;
}

int ***alloc_3d_arr(size_t xlen, size_t ylen, size_t zlen) { /* segue a mesma lógica da alocação para 2d, com um ajuste necessário para o acesso de modo usual */ 
    size_t i, j;

    int ***arr = malloc(xlen * sizeof(*arr));
    if (!arr) return NULL;

    arr[0] = malloc(xlen * ylen * sizeof(**arr));
    if (!arr[0]) {
        free(arr);
        return NULL;
    }

    arr[0][0] = malloc(xlen * ylen * zlen * sizeof(***arr));
    if (!arr[0][0]) {
        free(arr[0]);
        free(arr);
        return NULL;
    }

    for (i = 0; i < xlen; i++) {
        arr[i] = arr[0] + i * ylen;
        for (j = 0; j < ylen; j++) {
            arr[i][j] = arr[0][0] + (i * ylen + j) * zlen; /* as posições podem ser acessadas de modo usual*/
        }                                                  /* devido esse ajuste nos ponteiros */  
    }                                                      /* usei como base o link do stackoverflow referenciado acima*/

    return arr;
}

void free_3d_arr(int ***arr) {
    if (arr) {
        free(arr[0][0]);
        free(arr[0]);
        free(arr);
    }
}

void init_random(){
	long last_t;

	time(&last_t);
	srand((unsigned) last_t);
}

void init_3d_arr(int ***arr, int xlen, int ylen, int zlen){
	size_t i, j, k; 

	for(i = 0; i < xlen; i++)
		for(j = 0; j < ylen; j++)
			for(k = 0; k < zlen; k++)
				arr[i][j][k] = rand() % MAX_NUM; 

}

void choose_plane(int ***arr, int xlen, int ylen, int zlen){
	size_t i, j, k;
	char dim;

	printf("\ndeseja exibir qual plano?\n");
	

	do{
		printf("digite apenas a dimensão que será constante 'x', 'y' ou 'z'. ");
		printf("(digite 'q' para encerrar): ");
		
		scanf(" %c", &dim);
		
		switch(dim){
		case 'x':

			printf("digite o valor para x (x <= %d): ", xlen - 1);
			scanf(" %ld", &i);
			printf("o plano exibido será (%ld, y, z):\n\n", i);
			print_plane(i, dim, arr, xlen, ylen, zlen);
			return;

		case 'y':


			printf("digite o valor para y (y <= %d): ", ylen - 1);
			scanf(" %ld", &j);
			printf("o plano exibido será (x, %ld, z):\n\n", j);
			print_plane(j, dim, arr, xlen, ylen, zlen);
			return;

		case 'z':

			printf("digite o valor para z (z <= %d): ", zlen - 1);
			scanf(" %ld", &k);
			printf("o plano exibido será (x, y, %ld):\n\n", k);
			print_plane(k, dim, arr, xlen, ylen, zlen);
			return;

		case 'q':
			return;
		}
	}while(dim != 'q');
}

void print_plane(size_t choise, char ch_choise, int ***arr, int xlen, int ylen, int zlen){
	size_t i, j, k;

	switch(ch_choise){
	case 'x':
		i = choise;
		for(j = 0; j < ylen; j++){
			putchar('[');
			for(k = 0; k < zlen; k++){
				k != zlen - 1 ? printf("%2d ", arr[i][j][k]) : printf("%2d", arr[i][j][k]); 
			}
			putchar(']');
			putchar('\n');
		}
		break;
	
	case 'y':
		j = choise;
		for(i = 0; i < xlen; i++){
			putchar('[');
			for(k = 0; k < zlen; k++){
				k != zlen - 1 ? printf("%2d ", arr[i][j][k]) : printf("%2d", arr[i][j][k]); 
			}
			putchar(']');
			putchar('\n');
		}
		break;

	case 'z':
		k = choise;
		for(i = 0; i < xlen; i++){
			putchar('[');
			for(j = 0; j < ylen; j++){
				j != ylen - 1 ? printf("%2d ", arr[i][j][k]) : printf("%2d", arr[i][j][k]); 
			}
			putchar(']');
			putchar('\n');
		}
		break;
	}

	printf("\n--------------\n");
}

void action(int ***arr, int xlen, int ylen, int zlen){
	int choice;
	do{
		printf("vamos lá... o que deseja fazer:\n");
		printf("\n(1) para exibir um plano.\n");
		printf("(2) para alterar uma entrada do array 3D.\n");
		printf("(0) para encerrar o programa.\n\n");
		printf("sua escolha: ");

		scanf("%d", &choice);

		switch(choice){
		case 1:
			printf("\nok... vamos exibir um plano. ") ;
			choose_plane(arr, xlen, ylen, zlen);
			break;
		case 2:
			printf("beleza!\n");
			change_value(arr, xlen, ylen, zlen);
			break;
		case 0: 
			break;
		default:
			printf("opção inválida!\n");
		}
	}while(choice != 0);
}

void change_value(int ***arr, int xlen, int ylen, int zlen){
	size_t ni, nj, nk;
	int nvalue;

	printf("digite a posição que deseja alterar (x <= %d, y <= %d e z <= %d): ", xlen - 1, ylen - 1, zlen - 1);
	scanf("%ld %ld %ld", &ni, &nj, &nk);

	if (ni >= xlen || nj >= ylen || nk >= zlen) {
	    printf("erro: índices fora dos limites!\n");
	    return;
	}

	printf("\ndigite o novo valor para a entrada arr[%ld][%ld][%ld]: ", ni, nj, nk);
	scanf("%d", &nvalue);
	putchar('\n');

	printf("valor original: arr[%ld][%ld][%ld] = %d\n", ni, nj, nk, arr[ni][nj][nk]); 
	arr[ni][nj][nk] = nvalue;
	printf("valor atual: arr[%ld][%ld][%ld] = %d\n", ni, nj, nk, arr[ni][nj][nk]);

	printf("\n--------------\n");
}

int dim(int *xlen, int *ylen, int *zlen){
	printf("escolha as dimensões para o array 3D: ");
	scanf("%d %d %d", xlen, ylen, zlen); getchar();
	/* válida se as entradas são números inteiros positivos */
	if(*xlen <= 0 || *ylen <= 0 || *zlen <= 0){
		printf("erro: xlen, ylen e zlen devem ser positivos.\n");
		return 0;
	}
	putchar('\n');
	return 1;
}