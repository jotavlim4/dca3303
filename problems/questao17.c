#include <stdio.h>
#include <stdlib.h>

int main(){
	char *s = malloc(10 * sizeof(char)); //aloca dinâmicamente 10 bytes de memória no heap.
	int i;

	for(i = 0; i < 10; i++){
		s[i] = i;
		printf("s[%d] = %d\n", i, s[i]);
	}
	
	//free(s); //descomentar para resolver o memory leak.
	
	return 0;	
}

/*
memory leaky, ou vazamento de memória, é erro provocado, em geral, para situações envolvendo 
alocação dinâmica de memória.

basicamente ocorre quando usamos mallocs e não o pareamos com free. ou seja, alocamos dinâmicamente
memória no heap, mas após a utilização não desalocamos a memória utilizada fazendo com que essa região
continue ocupada desecessariamente.
*/
