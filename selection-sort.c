#include<stdio.h>
void display_array(int arr[],int n)
{
    printf("sorted array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
void selection_sort(int a[],int size)
{
    int  min,temp;
    for(int i=0;i<size-1;i++)
    {
       min = i ;
       for(int j=i+1;j<size;j++)
       {
        if(a[j] < a[min])
        {
            min = j;
        }
       }
       if(min != i)
       {
          temp = a[min];
          a[min] = a[i];
          a[i] = temp;
       }
    }
    display_array(a,size);
}
int main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elments :\n ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
}