#include <stdio.h>
#define MAX 50

void heapBottom(int a[MAX],int n);

int main(){
  int n,c,p,elt;
  scanf("%d",&n);
  int h[MAX];
  printf("Enter n values\n");
  for(int i=0;i<n;i++){
    scanf("%d",&h[i]);
  }
  printf("Before heapification:\n");
  for(int i=0;i<n;i++){
    printf("%d ",h[i]);
  }
  printf("\n");
  //Heapify
  // heapBottom(a,n);
  // int elt,c,p,k;
  int k;
  printf("%d",n);
  for(k=((n/2)-1);k>0;k--){
      printf("%d",k);
    p=k;
    elt=h[p];
    c=2*p+1;
    while(c<n){
      if(c+1<n){
        if(h[c+1]>h[c]){
          c=c+1;
        }
        if(elt<h[c]){
          h[p]=h[c];
          p=c;
          c=2*p+1;
        }
        else{
          break;
        }
      }
      h[p]=elt;
    }
  }
  printf("After heapification:\n");
  for(int i=0;i<n;i++){
    printf("%d ",h[i]);
  }
}

void heapBottom(int h[MAX],int n){
  int elt,c,p,k;
  printf("%d",n);
  for(k=((n/2)-1);k>0;k--){
      printf("%d",k);
    p=k;
    elt=h[p];
    c=2*p+1;
    while(c<n){
      if(c+1<n){
        if(h[c+1]>h[c]){
          c=c+1;
        }
        if(elt<h[c]){
          h[p]=h[c];
          p=c;
          c=2*p+1;
        }
        else{
          break;
        }
      }
      h[p]=elt;
    }
  }
}
