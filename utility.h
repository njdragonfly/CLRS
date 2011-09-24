#ifndef __INTRO_TO_ALGO_UTILITY
#define __INTRO_TO_ALGO_UTILITY

 
#include <stdio.h>

void print_int_array(int h[],int b,int e)
{
	int i;
	for(i=b;i<=e;i++) {
		printf("%d ",h[i]);
	}
	printf("\n");
}

#endif
