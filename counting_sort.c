#include<stdio.h>
void counting_sort(int a[],int size,int max)
{
    int count_arr[max];
    int b_arr[size];
    for(int i=0;i<size;i++)
    {
        ++count_arr[a[i]];
    }
    for(int i=1;i<=max;i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }
    for(int i = size-1; i >= 0; i--)
    {
        b_arr[--count_arr[a[i]]] = a[i];
    }
    for(int i=0;i<size;i++)
    {
        a[i]=b_arr[i];
    }
}
int main()
{
    int n,i;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i] > max)
        {
            max=arr[i];
        }
    }
    counting_sort(arr,n,max);
}