#include <stdio.h>

int main(){
	int i = 3, j = 5;
	int *p, *q;

	p = &i;
	q = &j;

	printf("%d\n", p == &i); /* compara os endereços de p e de i */
	printf("%d\n", *p - *q); /* subtrai o contéudo dos endereços apontados por p e q */
	printf("%x, %x\n", 	**&p); /* exibe o conteudo do endereço que p aponta, equivalente a *p */
	printf("%d\n", 3 - *p/(*q) + 7);

	return 0;
}

