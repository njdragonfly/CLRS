/*
 *
 */

#include "../utility.h"


void merge(int a[],int b[],int beg,int p,int end)
{
	int i,j,k;
	
	for(i=beg;i<=end;i++) {
		b[i]=a[i];
	}
	i=beg,j=p+1,k=beg;
	while(i<=p && j<=end) {
		if(b[i]<=b[j]) a[k++]=b[i++];
		else a[k++]=b[j++];
	}
	while(i<=p) a[k++]=b[i++];
	while(j<=end) a[k++]=b[j++];
}

void merge_sort(int a[],int b[],int beg,int end)
{
	int i,j;
	int p;
	
	if(beg>=end) return;
	p=(beg+end)/2;
	merge_sort(a,b,beg,p);
	merge_sort(a,b,p+1,end);
	
	merge(a,b,beg,p,end);
}

int main()
{
	int a[]={1,2,6,2,3,6,3,4,5,9,6,2,8,9,3,5,3,6,3,2};
	int b[sizeof(a)/sizeof(int)];
	merge_sort(a,b,0,sizeof(a)/sizeof(int)-1);
	print_int_array(a,0,sizeof(a)/sizeof(int)-1);
	return 0;
}
