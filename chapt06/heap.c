/*
 *  C implement of Introduction to Algorithms 2nd Edtion
 *
 *  Chapter 06
 *
 */

#include "../utility.h"

/*
 *
 * */

#define max_heapify(a,b,c) max_heapify_i(a,b,c)

void max_heapify_r(int h[],int length,int i)
{

	int l,r,large;
	int temp;
	if(i>=length/2) return;
	if(length<=1) return;

	l=2*i+1;
	r=2*i+2;

	large=i;
	if(h[large]<h[l]) large=l;
	if(r<length && h[large]<h[r]) large=r;

	if(large==i) return;

	temp=h[large];
	h[large]=h[i];
	h[i]=temp;

	max_heapify_r(h,length,large);

}

void max_heapify_i(int h[],int length,int i)
{
	int large,temp,l,r;
	while(i<=length/2-1) {
		l=2*i+1;
		r=2*i+2;
		large=i;
		if(h[l]>h[large]) large=l;
		if(r<length && h[r]>h[large]) large=r;
		if(large==i) break;
		temp=h[i];
		h[i]=h[large];
		h[large]=temp;
		i=large;
	}

}

void build_heap(int h[],int size)
{
	int i;
	for(i=size/2-1;i>=0;i--) {
		max_heapify(h,size,i);
	}
}

void heap_sort(int h[],int size)
{
	int i;
	int temp;
	build_heap(h,size);

	for(i=size-1;i>0;i--) {
		temp=h[0];
		h[0]=h[i];
		h[i]=temp;
		max_heapify(h,i,0);
	}

}


int main()
{
	int h[]={21,12,33,34,54,63,77};

	heap_sort(h,sizeof(h)/sizeof(int));
	print_int_array(h,0,sizeof(h)/sizeof(int)-1);

	return 0;

}



