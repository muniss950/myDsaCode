#include<stdio.h>
#define MAX 50
int main()
{
	int a[MAX];
	int i,c,p,n,elt;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//Heapify
	for(i=1;i<n;i++)
	{
		elt=a[i];
		c=i;
		p=(c-1)/2;
		while(c>0 && a[p]<elt)
		{
			a[c]=a[p];
			c=p;
			p=(c-1)/2;
		}
		a[c]=elt;
	}
 
//display heapified elements
	printf("\nElements of heap:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return 0;
}