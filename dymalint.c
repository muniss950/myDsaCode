#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  int n;
  scanf("%d",&n);
  int *array=malloc(sizeof(n));
  int xor=0;
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    array[i]=x;
  }
  for(int i=0;i<n;i++){
    xor^=array[i];
  } 
  printf("%d",xor); 
  return 0;
}
