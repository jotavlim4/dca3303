#include <stdio.h>


int f(int a, int *pb, int **ppc) { /*a = 5, pb = &c, ppc = &b */
  int b, c;
  
  **ppc += 1; /* 6 */
  
  c = **ppc; /* c = 6 */
  
  *pb += 2; /* 8 */
  
  b = *pb; /* b = 8 */
  
  a += 3; /* 8  */
  
  return a + b + c; /* 8 + 8 + 6  = 22*/
}


int main() {
  int c, *b, **a;
  /* *b armazena um endereço, **a armazena um endereço de uma variável que armazena endereço*/
  
  c = 5;
  b = &c;
  a = &b;
  
  printf("%d\n", f(c, b, a)); /* argmentos: valor de c, endereço de c, endereço de b */
  printf("%d \n", c);
  getchar();

  return 0;
}
