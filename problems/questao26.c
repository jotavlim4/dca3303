#include <stdio.h>

int main(){
  int a, b;
  int x, y, z;
  
  scanf("%d %d", &a, &b); /* suponha que a := 10, b := 1 */
  
  x = a; /* x := 10 (00001010) */
  y = b;  /* y := 1 (00000001) */
  z = a + b; /*z := 11 (00001011)*/
  
  while (a) {
    x = x | b;
    y = y ^ a; 
    z = z & (a+b);
    a = a >> 1; 
    b = b << 1; 
  }
  
  printf ("%d %d %d\n", x, y, z);
  return 0;
}

/*
primeira execução:
x = 11; => (00001010) or (00000001) => x := (00001011) := 11 
y = 11; =>  (00000001) xor (00001010) => y := (00001011) := 11
z = 11; => (00001011) and (00001011) => z := (00001011) := 11
a = 5; => (00001010) => (00000101) = 5
b = 2; =>  (00000001) => (00000010) = 2

segunda execução:
x = 11; => (00001011) or ((00000010) = (00001011) = 11;
y = 14; => (00001011) xor (00000101) = (00001110) = 14;
z = 3; => (00001011) and (00000111) = (00000011) = 3;
a = 2; => (00000101) => (00000010) = 2;
b = 4; => (00000010) => (00000100) = 4;

terceira execução:
x = 15; => (00001011) or (00000100) = 15;
y = 12; => (00001110) xor (00000010) = 12;
z = 2; => (00000011) and  (00000110) = 2;
a = 1; =>  (00000010) => (00000001) = 1;
b = 8; => (00000100) => (00001000) = 8;

quarta execução:
x = 15; => (00000101) or (00001000) = 15;
y = 13; => (00001100) xor (00000001) = 13;
z = 0; => (00000010) and (00001001) = 0;
a = 0; => (00000001) => (00000000) = 0;
b = 16; => (00001000) => (00010000) = 16;

fim do loop

valores exibidos
15 13 0;


a | b compara bit a bit e retorna 1 se pelo menos um dos bits comparados for 1;
a ^ b compara bit a bit e retorna 1 se os bit forem diferentes;
a & b compara bia bit re retonra 1 se ambos os bits forem 1, 0 caso contrário;
a >> k desloca todos os bits de a k bits para direita, equivale a dividir a por 2^k;
a << k desloca todos os bits de a k bits para esquerda, equivale a multiplicar a por 2^k;
 
*/