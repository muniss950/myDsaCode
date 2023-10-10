
#include <stdio.h>
#define MAX 50

int main(){
  int a[MAX];
  printf("Enter n values\n");
  int n,c,p,elt;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Before heapification:\n");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  //Heapify
  for(int i=0;i<n;i++){
    elt=a[i];
    c=i;
    p=(c-1)/2;
    while(c>0 && a[p]<elt){
      a[c]=a[p];
      c=p;
      p=(c-1)/2;
    }
    a[c]=elt;
  }
  printf("After heapification:\n");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}

