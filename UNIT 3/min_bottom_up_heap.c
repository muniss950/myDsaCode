#include<stdio.h>
#define MAX 100

void bottom_up_Min_Heap(int h[MAX], int n) 
{
    int elt, c, p, k;
    for (k=n/2-1; k>=0;k--) 
    {
        p=k;
        elt=h[p];
        c=2*p+1;
        while(c<n) 
        {
            if(c+1<n) 
            {
                if(h[c+1]<h[c]) // h[c+1]<h[c] for min heap  and h[c+1]>h[c] for max heap
                    c=c+1;
            }
            if(elt>h[c])    //(elt > h[c]) for min heap  and (elt < h[c]) for max heap
            {    
                h[p]=h[c];
                p=c;
                c=2*p+1;
            } 
            else 
            {
                break;
            }
        }
        h[p]=elt; 
    }
}

int main() 
{
    int h[MAX];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter n elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
    bottom_up_Min_Heap(h, n);
    printf("The min heap using bottom up approach\n");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);
    return 0;
}
