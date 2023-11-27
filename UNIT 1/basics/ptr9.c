#include  <stdio.h>
int swap(int *x,int *y);
int main()
{
      int  a, b;
      a = 5 ;   b = 20 ;
      swap (&a, &b) ;
      printf  ("\n a = %d,  b = %d", a, b);
}
int swap  (int  *x, int  *y)
{
      int  t ;
      t = *x ;
      *x = *y ;
      *y = t ;
}
