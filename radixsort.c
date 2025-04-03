#include<stdio.h>
#include<stdlib.h>
int findmax(int a[],int size)
{
    int maxi = a[0];
    for(int i=0;i<size;i++)
    {
       if(a[i]>maxi) 
       {
        maxi = a[i];
       }
    }
    return maxi;
}
void countsort(int arr[],int n,int position) 
{
   int count_arr[10] = {0};
   int b[n];
   for(int i=0;i<n;i++)
   {
     ++count_arr[(arr[i]/position) % 10];
   }
   for(int i=1;i<10;i++)
   {
    count_arr[i]=count_arr[i]+count_arr[i-1];
   }
   for(int i=n-1;i>=0;i--)
   {
    b[--count_arr[(arr[i]/position) % 10]] = arr[i];
   }
   for(int i=0;i<n;i++)
   {
    arr[i]=b[i];
   }
}
void radixsort(int a[],int size,int max_value)
{
    for(int pos = 1; max_value/pos > 0 ; pos = pos*10)
    {
        countsort(a,size,pos);
    }
}
void display(int a_arr[],int size)
{
    printf("sorted array : \n");
    for(int i=0;i<size;i++)
    {
        printf("%d  ",a_arr[i]);
    }
}
int main()
{
    int n,max;
    printf("enter size of array \n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values of array \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max = findmax(arr,n);
    radixsort(arr,n,max);
    display(arr,n);
}