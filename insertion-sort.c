#include<stdio.h>
int main()
{
    int n,temp,j;
    printf("enter the size of array \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the values of unsorted array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("your sorted array : ");
    for(int i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}