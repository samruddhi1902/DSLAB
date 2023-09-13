#include<stdio.h>

void bubblesort(int arr[],int n)
{
    int i,j,temp;
    int count=0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                count++;
            }
        }
        if(count==0){
            return bubblesort(arr,n-1);
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
    bubblesort(arr,n);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}