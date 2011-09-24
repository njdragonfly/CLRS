
#include "heap.hpp"

template <typename T>
Heap<T>::Heap(T v[],int s) {
	data=v;
	size=s;
	for(int i=size/2-1;i>=0;i--) {
			max_heapify(i);
	}
}

template <typename T>
void Heap<T>::remove() {
	size--;
	T tmp=data[0];
	data[0]=data[size];
	data[size]=tmp;
	max_heapify(0);
}

template <typename T>
void Heap<T>::max_heapify(int i) {
	int l=0,r=0,t=0;
	while(i<=size/2-1) {
		l=2*i+1;
		r=l+1;
		t=i;
		if(data[t]<data[l]) t=l;
		if(r<size && data[t]<data[r]) t=r;
		if(t==i) break;
		T tmp=data[t];
		data[t]=data[i];
		data[i]=tmp;
		i=t;
	}
}

template <typename T>
void heap_sort(T h[],int size)
{
	int i;
	T temp;
	Heap<T> heap(h,size);
	for(i=size-1;i>=0;i--) {
		heap.remove();
	}
}

#include <iostream>
using namespace std;
void print_int_array(int h[],int b,int e)
{
	int i;
	for(i=b;i<=e;i++) {
		cout<<h[i]<<" ";
	}
	cout<<endl;
}

///*
int main() {
	int h[]={21,12,33,34,54,63,77};
	heap_sort(h,sizeof(h)/sizeof(int));
	print_int_array(h,0,sizeof(h)/sizeof(int)-1);
	return 0;
}
//*/
