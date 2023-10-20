#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct node{
  int data;
  struct node *next;
}node;
node a[100];
void indegree(node **a,int i,int j);
void outdegree(node **a,int i,int j);
void display(int data);

int main(){
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
void display(int n){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){

    }
  }
}
void indegree(node **a,int i,int j){
  node* temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=j;
  temp->next=a[i];
  a[i]=temp;
}
void outdegree(node **a,int i,int j){
  node* temp;
  int i,j;
  int count;
  temp a[v]; 
  temp=(node*)malloc(sizeof(node));
  temp->data=j;
  temp->next=a[i];
  a[i]=temp;
}
