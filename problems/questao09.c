#include <stdio.h>


int main(){
	int mat[4] = {1, 2, 3, 4};
	int *p, x;


	p = mat + 1; /* legal */
	p = mat++; /* ilegal, pois envolve atrbuição de arrays */
	p = ++mat; /* ilegal, pois envolve atrbuição de arrays */
	x = (*mat); /* legal */

	return 0;
}