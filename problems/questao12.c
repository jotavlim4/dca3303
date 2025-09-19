#include <stdio.h>

int main(){
	int const x = 10;
	int const *px = NULL;

	px = &x;

	printf("%d\n", ++px);

	return 0;
}

/* 4: int const *x = 3; */
/* 
nessa linha estamos tentando inicialiar x, que é um ponteiro para int const, 
com o valor inteiro literal 3.

isso vai gerar um erro de compilação, pois literais numericos são tratados pelo compiltador, 
por padrão como int. mas x é declarada como um ponteiro, logo se espera que a x seja atribuido
um endereço de memória.
*/


/* 6: printf("%d\n", ++(*x)); */
/*
suponha que o problema da linha 4 tenha sido resolvido.

a linha 6 nos traria outro problema pois x é um ponteiro para int const, ou
seja, não temos acesso a modificar o que está na região de memória apontada
por x.

logo essa operação de atribuição que estamos tentando fazer é ilegal.

nada nos impede de mudar a direção para o qual x aponta, mas nao conseguimos
mudar o conteúdo do endereço apontado por x.
*/