#include <stdio.h>
#include <string.h>

struct teste{
  int x;
  char nome[100];
};

int main(){
  struct teste pessoa;
  struct teste *pp; // pp é um ponteiro para teste.

  pp = &pessoa; //faz pp apontar para o endereço de pessoa.

  strcpy(pp -> nome, "josé");
  pp -> x = 3;

  printf("%d\n", pp->x);
  printf("%s\n", pp->nome); /* equivale a (*pp).nome*/

  return 0;
}
