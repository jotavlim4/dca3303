#include <stdio.h>

#define TAM 10


/* retorna o indice da primeira ocorrencia de v em vetor iterando sobre vetor */
/* de modo geral, faz uma busca sequencial */
/* a complexidade nesse caso depende da quantidade de elementos O(n) */

int funcao1(int vetor[], int v){
  int i;

  for (i = 0; i < TAM; i++){
    if (vetor[i] == v)
      return i;
  }
  
  return -1;
}

/* retorna o indice da ocorrencia de v em vetor aplicando recursividade */
/* a estrateǵia de busca lembra um pouco busca binária, se for o caso, procura sempre na metade superior ou inferior */
/* essa estratégia é possível pois o vetor declarado em main já está ordenado */
/* se eu nao me engando a complexidade é O(log n) */

int funcao2(int vetor[], int v, int i, int f){
  int m = (i + f) / 2;
  
  if (v == vetor[m])
    return m;
  
  if (i >= f)
    return -1;
  
  if (v > vetor[m])
    return funcao2(vetor, v, m+1, f);
  else
    return funcao2(vetor, v, i, m-1);
}

int main(){
  int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  
  printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM-1));
  
  return 0;
}


/*

apenas I está correto.

ambos são algoritmos de busca que retornam o indice do valor procurado. 
note que na chamada da função o valor procurado é 15 que se encontra na 7 posição
do vetor declarado em main.

logo 7-7 é o que será exibido.

II é incorreto. a funcão1 performa uma busca sequencial, isso significa que no pior caso, 
quando 15 está na ultima posição do vetor ela terá complexidade O(n); enquando funcao2 no pior caso, 
tem complexida O(log n).

III está incorreto, pois a estratégia implementada é recursiva.

resposta correta letra a.


*/