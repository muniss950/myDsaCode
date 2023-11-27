#include<stdio.h>
int main()
{
  
  int a[2][4]={1,2,3,4,5,6,7,8};
  int (*y)[4];
  //int *y;
  printf("\na=%d\n",a);
  printf("a+1=%d\n",a+1);

  printf("\n&a=%d\n",&a);
  printf("\n&a+1=%d\n",&a+1);
  
  y=&a;
  printf("y=%d\n",y);

}

 
