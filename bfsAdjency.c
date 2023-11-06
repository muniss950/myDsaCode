#include <stdio.h>
#include <stdlib.h>


#define MAX 100

typedef struct node{
  int info;
  struct node* next; 
}N;

void createList(N *A[MAX]);
void addEdge(N* A[MAX],int src,int dest);
void bfs(N* A[MAX],int visited[MAX],int src);

int main(){
  int src,n;
  int visited[MAX]={0};
  N *A[MAX]={NULL};
  createList(A);
  printf("Enter the source vertex\n");
  scanf("%d",&src);
  printf("BFS traversal\n");
  bfs(A,visited,src);
}


void createList(N *A[MAX]){
  int src,dest,choice;
  do{
    printf("Enter the src and dest \n");
    scanf("%d %d",&src,&dest);

    addEdge(A,src,dest);
    addEdge(A,src,dest);

    printf("Do you want to add one more edge\n");
    scanf("%d",&choice);
  }while(choice);
}
void addEdge(N* A[MAX],int src,int dest){
  N* newNode=malloc(sizeof(N));
  newNode->info=dest;
  newNode->next=A[src];
  A[src]=newNode;
}
void bfs(N* A[MAX],int visited[MAX],int src){
  int q[MAX];// declaring queue
  int f=0,r=-1;//front and rear
  int w;
  q[++r]=src;
  visited[src]=1;
  while(f<=r){
    w=q[f++];
    printf("%d->",w);
    N*p=A[w];
    while(p!=NULL){
      if(visited[p->info]==0){
        q[++r]=p->info;
        visited[src]=1;
      }
      p=p->next;
    }
  }
}
