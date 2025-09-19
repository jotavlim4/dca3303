#include <stdio.h>

/* variáveis globais */
char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"}; /* vetor de ponteirso para char */
char **b[] = {a + 3, a + 2, a + 1, a}; /* vetor de ponteiro de ponteiros para char */
char ***c = b; /* ponteiro de ponteiro de ponteiro para char */

int main() {
  printf("%s ", **++c);
  printf("%s ", *--*++c + 3);
  printf("%s ", *c[-2] + 3);
  printf("%s ", c[-1][-1] + 1);
  return 0;
}

/*

(1) printf("%s ", **++c);

c => &b[0]
++c => (&b[0] += 1) => ((b + 1))  => (&b[1])
*++c => *(&b[1]) => (a + 2) => (&a[0] + 2) => (&a[2])
**++c => *(&a[2]) => "BRITO"

  
(2) printf("%s ", *--*++c + 3);

 c => &b[1];
 ++c => (&b[1] += 1) => ((b + 1) + 1)  => (&b[2])
*++c => *(&b[2]) => (a + 1) => (&a[0] + 1) => (&a[1])
--*++c => --(&a[1]) => &a[1] -= 1 => (a + 1) - 1 =>  (a + 0) => a
*--*++c => *(a) => *(&a[0]) => &a[0][0]
*--*++c => &a[0][0] + 3 => &a[0][3]; => "STINHO";

(3) printf("%s ", *c[-2] + 3);

c => &b[2];
c[-2] => (b + 2) - 2 => b
*c[-2] => *(b) => *(&a[3]) => *(a + 3) => &a[3][0];
*c[-2] + 3 = &a[3][0] + 3 => &a[3][3] => "IOR"

(4) printf("%s ", c[-1][-1] + 1);

c =>  &b[2];
c[-1] => &b[2] - 2 => (b + 2) - 1 => b + 1 => b[1];
c[-1][-1] => b[1] - 1 => (b + 1) - 1 => b => &a[0];
c[-1][-1] + 1 => &a[0] + 1 => a + 1 => &a[1] => "MEDEIROS"


*/