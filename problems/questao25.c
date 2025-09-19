//(C)
int f(char *data){
  void *s;

  s = malloc(50);
  int size = strlen(data);

  if (size > 50)
    return (-1);
  
  free(s);
  return 0;
}

/*

esse trecho tem vazamento de memória, 
uma vez que, se ocorrer de size for maior 
de 50, a função retorna -1 e o free nunca é
executado.

*/

/* solução */

int f(char *data){
  void *s = malloc(50 * sizeof(char));

  int size = strlen(data);

  if(size > 50){
    free(s);
    return - 1;
  }

  free(s);
  return 0;
}