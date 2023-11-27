#include<stdio.h>
#define MAX 50
void bottomUpMaxHeap(int h[MAX],int n)
{
	int c,p,key;
	
	for(int k=n/2-1;k>0;k--)
	{
		p=k;
		key=h[p];
		c=2*p+1;
		while(c<n)
		{
			if(c+1<n)
				if(h[c+1]>h[c])
					c=c+1;
				if(key<h[c])
				{
					h[p]=h[c];
					p=c;
					c=2*p+1;
				}
				else
					break;
		}
		h[p]=key;
	}
}

int maxDelete(int h[MAX],int *n)
{
	int ele=h[0];
	h[0]=h[*n-1];
	(*n)--;
	bottomUpMaxHeap(h,*n);
	return ele;
}

int main()
{
	int h[MAX],n;
	
	printf("ENter the NO. of elts\n");
	scanf("%d",&n);
	
	printf("Enter the elts\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	
	bottomUpMaxHeap(h,n);
	printf("Bottom up heap:\n");
	for(int i=0;i<n;i++)	
		printf("%d\t",h[i]);
}
