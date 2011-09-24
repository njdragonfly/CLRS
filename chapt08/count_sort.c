/*
 *
 */

#include "../utility.h"

void count_sort(int a[],int size)
{
	int i,j;
	int * p;
	int c[10]={0};
	p=(int*)malloc(sizeof(int)*size);
	for(i=0;i<size;i++) { c[a[i]]++; p[i]=a[i];}
	#ifdef _ONLY_NUMBER_
	//这种算法只适用于整数
	j=0;
	for(i=0;i<10;i++) {
		while(c[i]>0) {
			a[j]=i;
			j++;
			c[i]--;
		}
	}
	#endif

	for(i=1;i<10;i++) c[i]+=c[i-1];

	//这里很重要
	for(i=size-1;i>=0;i--) {
		a[c[p[i]]-1]=p[i];
		c[p[i]]--;
	}
	free(p);
}

int main()
{
	int a[]={1,2,6,2,3,6,3,4,5,9,6,2,8,9,3,5,3,6,3,2};
	count_sort(a,sizeof(a)/sizeof(int));
	print_int_array(a,0,sizeof(a)/sizeof(int)-1);
	return 0;
}
