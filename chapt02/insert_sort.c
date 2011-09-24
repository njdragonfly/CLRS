/*
 *
 */

#include "../utility.h"



void insert_sort(int a[],int beg,int end)
{
	int i,j;
	int temp;
	i=beg+1;
	while(i<=end) {
        j=i-1;
        while(j>=beg && a[j]>a[j+1]) {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            j--;
        }
        i++;
    }

}

int main()
{
	int a[]={12,21,65,25,35,6,73,4,45,97,6,28,890,-9,33,51,32,63,3,2};
	insert_sort(a,0,sizeof(a)/sizeof(int)-1);
	print_int_array(a,0,sizeof(a)/sizeof(int)-1);
	return 0;
}
