

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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

typedef struct stackQueue{
  queue *q1,*q2;
}stack;
stack* createStack();
void push(stack *s,int value);
int pop(stack *s);

int main(){
  stack *s=createStack();
  int op;
  scanf("%d",&op);
  for(int i=0;i<op;i++){
    int value;
    scanf("%d",&value);
    if(value){
      int inp;
      scanf("%d",&inp);
      push(s,inp);
    }
    else{
      pop();
    }
  }
}

stack* createStack(){
  stack* s=malloc(sizeof(stack));
  s->q1=createQueue();
  s->q2=createQueue();
  return s;
}
void push(stack *s,int value){
  while(s->q1->front!=NULL){
    insert(&(s->q2),removeElem(&(s->q1)));
  }  
  insert(&(s->q1),value);
  while(s->q2->front!=NULL){
    insert(&(s->q1),removeElem(&(s->q2)));
  }  

}
int pop(stack *s){
  int data=removeElem(&(s->q1));
  printf("%d\n",data);
  return data;
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
