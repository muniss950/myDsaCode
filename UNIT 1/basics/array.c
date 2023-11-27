#include<stdio.h>
void display(int*, int);
int main()
{

  int a[4]={1,2,3,4};
  
  display(a,3);
}

 void display(int *a, int n)
 {
    int i;
   for (i=0;i<=n;i++)
   {
     printf("\nThe address of %d element = %d\n",i,a);
     printf("\nThe value of %d element = %d\n",i,*a);
     a++;
    }
}
 
