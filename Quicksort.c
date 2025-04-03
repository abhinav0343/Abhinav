#include<stdio.h>
#include<stdlib.h>
void display(int ar[],int size)
{
    printf("sorted array : \n");
    for(int i=0;i<size;i++)
    {
      printf("%d ",ar[i]);
    }
}
int partition(int a_arr[],int lower_bound,int upper_bound)
{
   int start,end,pivot,temp;
   pivot = a_arr[lower_bound];
   start = lower_bound;
   end = upper_bound;
   while(start < end) {
     while(a_arr[start] <= pivot && start < upper_bound)
     {
        start++;
     }
     while(a_arr[end] > pivot && end > lower_bound) 
     {
        end--;
     }
     if(start < end) 
     {
        temp = a_arr[start];
        a_arr[start] = a_arr[end];
        a_arr[end] = temp;
     }
   }
   temp = a_arr[lower_bound];
   a_arr[lower_bound] = a_arr[end];
   a_arr[end] = temp;
   return end;
}
void quicksort(int a[],int lower,int upper)
{
    int position;
    if( lower < upper) {
        position = partition(a,lower,upper);
        quicksort(a,lower,position-1);
        quicksort(a,position+1,upper);
    }
}
int main()
{
    int n;
    printf("enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int low = 0 , upp = n-1;
    quicksort(arr,low,upp);
    display(arr,n);
}