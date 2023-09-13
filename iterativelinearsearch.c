#include<stdio.h>

void lsearch(int arr[],int n,int m)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==m)
        {
            flag=1;
            printf("Element found");
        }
    }
    if(flag==0)
    {
        printf("Element not found");
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
    printf("enter the element you want to find:");
    scanf("%d",&m);
    lsearch(arr,n,m);
}