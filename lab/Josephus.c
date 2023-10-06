#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct queue{
  struct node *front,*rear;
}queue;
typedef struct node{
  int data; 
  struct node* next;
}node;
queue* createQueue();
void insert(queue** q,int value);
int removeElem(queue** q);
void display(queue* q);
bool isEmpty(queue*q);
void findTheWinner(int n,int m);

int main(){
 int n,m; 
  scanf("%d",&n);
  scanf("%d",&m);
  findTheWinner(n,m);
}

void findTheWinner(int n,int m){
  queue* q=createQueue();
  for(int i=1;i<=n;i++){
    insert(&q,i);
  }
  while(q->front!=q->rear){
    for(int j=1;j<m;j++){
      int temp=q->front->data;
      insert(&q,temp);
      removeElem(&q);
    }
    removeElem(&q);
  }
  printf("%d\n",q->front->data);
}
queue* createQueue(){
  queue* q=malloc(sizeof(queue)); 
  q->front=q->rear=NULL;
  return q;
}
void insert(queue** q,int value){
  if((*q)->front==NULL){
    node* temp=malloc(sizeof(node));
    temp->data=value;
    temp->next=NULL;
    (*q)->front=(*q)->rear=temp;
    return;
  }
    node* temp=malloc(sizeof(node));
    temp->data=value;
    temp->next=NULL;
    (*q)->rear->next=temp;
    (*q)->rear=temp;
  return;
}
int removeElem(queue** q){
  if((*q)->front==NULL){
    printf("Queue underflow\n");
    return -1;
  }
  node* temp=(*q)->front;
  int data=temp->data;
  (*q)->front=(*q)->front->next;
  free(temp);
  return data;
}
void display(queue* q){
  if((q)->front==NULL){
    printf("Empty queue\n");
    return;
  }
  node* temp=(q)->front;
  printf("%d ",temp->data);
  while(temp!=q->rear){
    temp=temp->next;
    printf("%d ",temp->data);
  }
  printf("\n");
  return;
}
bool isEmpty(queue*q){
  if((q)->front==NULL){
    printf("Queue is Empty\n");
    return true;
  }
  printf("Queue is not Empty\n");
  return false;
}
