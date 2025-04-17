#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define BUCKET_COUNT 10
struct bucket {
    float values[SIZE];
    int count;
};
void insertionsort(float a[],int size) {
    for(int i=1;i<size;i++)
    {
        float temp = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > temp ) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
void bucketsort(float arr[],int n)
{
    struct bucket buckets[BUCKET_COUNT];
    for(int i=0;i<BUCKET_COUNT;i++)
    {
        buckets[i].count = 0;
    }
    for(int i=0;i<n;i++)
    {
        int index = arr[i] * BUCKET_COUNT;
        if(index >= BUCKET_COUNT) {
            index = index-1;
        }
        buckets[index].values[buckets[index].count++] = arr[i];
    }
    int k=0;
    for(int i=0;i<BUCKET_COUNT;i++)
    {
        if(buckets[i].count > 0) {
            insertionsort(buckets[i].values,buckets[i].count);
            for(int j=0;j<buckets[i].count;j++)
            {
                arr[k++]=buckets[i].values[j];
            }
        }
    }
}
int main()
{
    float arr[]={0.42,0.32,0.23,0.52,0.25,0.47,0.51,0.99,0.05};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("inital array :\n");
    for(int i=0;i<n;i++)
    {
        printf("%f ",arr[i]);
    }
    bucketsort(arr,n);
    printf("sorted array : \n");
    for(int i=0;i<n;i++)
    {
        printf("%f ",arr[i]);
    }
    return 0;
}