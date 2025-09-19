#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 5

void matrix_m(int **A, int **B, int **C, int lineA, int colA, int colB);
void test(int **m1, int **m2, int **res, int nl1, int nc1, int nc2);
void init_random();
void init_m(int **m, int l, int c);
int **alloc_mat(int nl, int nc);
void print_m(int **m, int nl, int nc);

int main(){
    int line, col1, col2;
    int **m1, **m2, **m;

    init_random();

    scanf("%d %d %d", &line, &col1, &col2);
    if(line <= 0 || col1 <= 0 || col2 <= 0)
        return 1;

    /* aloca dinâmicamente as matrizes */
    m1 = alloc_mat(line, col1);
    m2 = alloc_mat(col1, col2);
    m = alloc_mat(line, col2);

    /* testa */
    test(m1, m2, m, line, col1, col2);

    /* desaloca a memória e evita memory leak */
    free(m);
    free(m2);
    free(m1);

    return 0;
}

/* matrixm: multiplica matrizes fazendo o produtos escalar, dot product, entre linhas e colunas */
void matrix_m(int **A, int **B, int **C, int lineA, int colA, int colB){
    int i, j, k;

    for(i = 0; i < lineA; i++)
        for(j = 0; j < colB; j++)
            for(k = 0; k < colA; k++)
                C[i][j] += A[i][k] * B[k][j];   
}

void init_random(){
    long last_t;

    time(&last_t);
    srand((unsigned) last_t);
}

void init_m(int **m, int l, int c){
    int i, j;

    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
            m[i][j] = rand() % RANGE;
}

int **alloc_mat(int nl, int nc){
    int i;
    int **m = malloc(nl * sizeof(int*));

    if(m == NULL)
        return NULL;

    m[0] = malloc(nl * nc * sizeof(int));

    if(m[0] == NULL){
        free(m);
        return NULL;
    }
    
    for(i = 1; i < nl; i++)
        m[i] = m[i - 1] + nc;

    return m;
}

void print_m(int **m, int nl, int nc){
    int i, j;

    for(i = 0; i < nl; i++){
        putchar('[');
        for(j = 0; j < nc; j++)
           j == nc - 1 ? printf("%2d", m[i][j]) : printf("%2d ", m[i][j]);
        putchar(']');
        putchar('\n');
    }
}

void test(int **m1, int **m2, int **res, int nl1, int nc1, int nc2){
    /* inicializa as matrizes com valores aleatorios entre 0 e (RANGE - 1) */
    init_m(m1, nl1, nc1);
    init_m(m2, nc1, nc2);

    /* performa o algoritmo da multiplicação de matrizes */
    matrix_m(m1, m2, res, nl1, nc1, nc2);

    /* exibe as matrizes: */
    printf("mat1:\n");
    print_m(m1, nl1, nc1);
    printf("-------\n");

    printf("mat2:\n");
    print_m(m2, nc1, nc2);
    printf("-------\n");

    printf("mat_m:\n");
    print_m(res, nl1, nc2);
}