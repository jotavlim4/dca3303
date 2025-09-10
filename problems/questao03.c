#include <stdio.h>

int main(){
	int *p, *q;
	int i, j;

	p = &i;
	*q = &j;
	p = &*&i;
	i = (*&)j;
	i = *&j;
	i = *&*&j;
	q = *p;
	i = (*p)++ + *q;
	
	return 0;
}