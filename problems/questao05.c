#include <string.h>
#include <stdio.h>
#include <stdlib.h>

 
void funcao(char **str){
	/* estamos modificando o endereço de armazenado em str,  */
	/* fazendo com que str agora aponte para para o próximo byte. */
	(*str)++; 
}

int main(){
	/* str é um ponteiro para char que está armazenando o endereço retornado por malloc. */
	char *str = (void *) malloc(10 * sizeof(char));

	/* aqui estamos copiando para str a string "Agostinho" */
	/* strcpy recebe como argumento o endereço para o qual str aponta, pois em C só existe passagem por valor */
	/* após isso, modifica os bytes do endereço apontado por str*/
	strcpy(str, "Agostinho");
	
	/* estamos passando para 'funcao' o endereço de str que por sua vez armazena um outro endereço */
	funcao(&str);
	puts(str); /* imprimimos str que agora aponta para 1byte a frente */
	free(str - 1); /* subtraimos 1 unidade para que str volte a aponta para o endereço retornado por malloc. */

	return 0;
}

