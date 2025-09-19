#include <stdio.h>

int main(){
	float aloha[10], coisas[10][5], *pf, value = 2.2;
	int i=3;

	aloha[2] = value; /* válido */
	scanf("%f", (float *) &aloha); /* válido, atribui o valor lido por scanf para aloha[0] */
	//aloha = "value"; /* invalido */
	printf("%f", aloha); /* válido */
	coisas[4][4] = aloha[3]; /* válido */
	//coisas[5] = aloha; /* inválido, tentativa de atribuição entre arrays */
	//pf = value; /* invalido, tenta atribuir um valor inteiro a um ponteiro para float. */
	pf = aloha; /* válido, atribui a pf o endereço de aloha[0] */



 

	return 0;
}