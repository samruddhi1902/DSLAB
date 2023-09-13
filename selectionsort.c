#include<stdio.h>

void selectionsort(char arr[],int n)
{
    int i,j,temp,a,b;
    for(i=0;i<n-1;i++)
    {
        int imin=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[imin])
            {
                imin=j;
            }
        }
            temp=arr[imin];
            arr[imin]=arr[i];
            arr[i]=temp;
            
        }
    }

int main()
{
    int i,m,n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    char arr[n];
    printf("enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%s",&arr[i]);
    }
    selectionsort(arr,n);
    printf("Sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%c\t",arr[i]);
    }
    return 0;
}