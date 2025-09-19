#include <stdio.h>

void funcao(char **p){ /* p é o endereço do primeiro vetor apontado por a, ou seja, o endereço de a[0] = "ab" */
	char *t; /* t é um ponteiro para char */
	t = (p += sizeof(int))[-1]; /* p é incrementado em 4 bytes, ou seja, p + 4 = p[4] que é o endereço de "ij" e em seguida (p + 4)[-1] = (p + 3) = p[3] que é o endereço de  "gh" */
	printf("%s\n", t); /* imprime "gh" */
}

int main(){
	char *a[] = {"ab", "cd", "ef", "gh", "ij", "kl"}; /* vetor de ponteiros */
	funcao(a); /* passa para função o endereço do primerio vetor apontado por a, ou seja, o endereço de a[0] = "ab" */
	return 0;
}