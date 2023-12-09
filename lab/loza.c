rgerg
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
int main(){

  queue* q=createQueue();
  while(1){
    system("clear");
      printf("Simple Queue implementation using Array \n");
      printf("-----------------------\n");
  printf("1.Display\n2.Insert\n3.Remove\n4.isEmpty\n5.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      display(q);
      break;
    }
    case 2:{
      printf("Enter your value to be inserted: ");
      int value;
      scanf("%d",&value);
      insert(&q,value);
      printf("Value inserted.\n");
      break;
    }
    case 3:{
      printf("Removing Element..\n");
      int data=removeElem(&q);
      printf("%d removed\n",data);
      break;
    }
    case 4:{
        isEmpty(q);
        break;
      }
    case 5:{
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
