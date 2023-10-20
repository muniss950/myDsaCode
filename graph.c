
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int indegree(int (*a)[100],int n,int v);
int outdegree(int (*a)[100],int n,int v);
void display();
void  createGraph(int (*a)[100],int n);
int main(){
  int a[100][100];
  int n;
  int i,v;
  printf("Enter the size: ");
  scanf("%d",&n);
  while(1){
    system("clear");
    printf("-----------------------\n");
    printf("1.Indegree\n2.Outdegree\n3.Display\n4.Exit\n");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
        printf("Enter the vertex\t");
        scanf("%d",&v);
        i=indegree(a,n,v);
        printf("Indegree of a vertex=%d",i);
        break;
    }
    case 2:{
        printf("Enter the vertex\t");
        scanf("%d",&v);
        i=indegree(a,n,v);
        printf("Indegree of a vertex=%d",i);
        break;
      }
    case 3:{
        display();
        break;
    }
    case 4:{
        goto exitLoop;
        break;
      }
    default:{
      printf("Enter valid choice: \n");
    }
  }
  
  char stop;
      printf("Press any key+Enter to continue...");
      scanf(" %c",&stop);
  }
  exitLoop:;

}
void  createGraph(int (*a)[100],int n){
  int i,j;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      a[i][j]=0;
    }
  }
  while(1){
    printf("Enter the source and destination: ");
    scanf("%d %d",&i,&j);
    if((i==-9)&&(j==-9)){
      break;
    }
    a[i][j]=1;
    a[j][i]=1;
  }
}
void display(int n){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){

    }
  }
}

int indegree(int (*a)[100],int n,int v){
  return -1;
}
int outdegree(int (*a)[100],int n,int v){
  return -1;
}
