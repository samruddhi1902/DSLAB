#include<stdio.h>

void bubblesort(int arr[],int n)
{
    int i,j,temp;
    int rounds=0;
    for(i=0;i<n-1;i++)
    {
        rounds++;
        int flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==0)
        {
            break;
        }
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
        printf("%d\t",arr[i]);
    }
    return 0;
}