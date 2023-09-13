#include<stdio.h>

void insertionsort(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=current;
    }
}
int main()
{
    int i,m,n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d   ",arr[i]);
    }
    return 0;
}