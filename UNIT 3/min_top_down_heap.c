#include<stdio.h>
#define MAX 100
int main()
{
    int a[MAX];
    int i,c,p,n,ele;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //Heapify
    for(i=1;i<n;i++)
    {
        ele=a[i];
        c=i;
        p=(c-1)/2;
         while(c>0 && a[p]>ele) // a[p]>ele for ascending and a[p]<ele for descending
            {
                a[c]=a[p];
                c=p;
                p=(c-1)/2;
            }
        a[c]=ele;
    }  
    printf("\n heap top up approach in ascending :\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}