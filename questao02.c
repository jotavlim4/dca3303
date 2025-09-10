#include <stdio.h>

int main(){
	int i = 5, *p;
	p = &i;
	printf("%p %p %d %d %d %d\n", p, p + 1, *p+2, **&p, 3**p, **&p+4);

	return 0;
}

/*

p        -> o endereço de p (4094)
p + 1    -> o endereço de p incrementado em 1 byte (4096)
*p + 2   -> conteudo do endereço apontado por p mais 2 (7)
**&p     -> conteudo do endereço que p aponta (5)
3**p     -> 3 vezes o conteúdo apontado por p (15)
**&p + 4 -> o conteúdo do endereço apontado por p + 4 (9) 

	
*/