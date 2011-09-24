/*
 *
 */

#include "../utility.h"

/*
* a 待排序的数组
* p,r为数组下标
*/
int quick_partition(int a[],int p,int r)
{
    int pivot;
    int temp; 
    int i,j;
    //assert(p<=r);
    pivot=(p+r)/2; //选择轴值位置，与算法效率有关系 
    temp=a[pivot];
    a[pivot]=a[r];
    
    i=p,j=r;
    while(i<j) {
               while(i<j && a[i]<=temp) i++;
               if(i==j) break;
               a[j]=a[i];
               j--;
               while(j>i && a[j]>temp) j--;
               if(i==j) break;
               a[i]=a[j];
               i++;
    }
    a[i]=temp;
    return i;
}
void quick_sort(int a[],int p,int r)
{
     int pivot;
     if(p>=r) return;
     pivot=quick_partition(a,p,r);
     quick_sort(a,p,pivot-1);
     quick_sort(a,pivot+1,r);
}

int main()
{
    int a[]={1,25,6,7,62,65,56,7,8,878,92};
    quick_sort(a,0,sizeof(a)/sizeof(int)-1);
    print_int_array(a,0,sizeof(a)/sizeof(int)-1);
    return 0;
}

