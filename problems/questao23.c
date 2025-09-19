#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vsum(int *s1, int *s2, int *s, int l);
void initv(int *v, int l);
void printv(int *v, int l); 

int main(){
    int len;
    long ultime;

    /* referencia: luiz damas, linguagem c, pág. 148, cap. 6 */
    time(&ultime);
    srand((unsigned) ultime);

    scanf("%d", &len);
    if(len <= 0)
        return 1;

    int *v1 = malloc(len * sizeof(int));
    int *v2 = malloc(len * sizeof(int));
    int *sum = malloc(len * sizeof(int));

    if( v1 == NULL || v2 == NULL || sum == NULL)
        return 1;

    initv(v1, len);
    initv(v2, len);
    
    vsum(v1, v2, sum, len);

    printv(v1, len);
    printv(v2, len);
    printv(sum, len);

    free(sum);
    free(v2);
    free(v1);

    return 0;
}

void vsum(int *s1, int *s2, int *s, int l){
    int i;

    for(i = 0; i < l; i++)
        s[i] = s1[i] + s2[i];
}


void initv(int *v, int l){
    int i;
    
    for(i = 0; i < l; i++)
        v[i] = rand() % l;
}

void printv(int *v, int l){
    int i;
    for(i = 0; i < l; i++)
        printf("%2d ", *(v + i)); /* *(v + i) := v[i] */
    putchar('\n');
}