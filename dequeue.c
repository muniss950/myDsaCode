
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000
typedef struct dequque{
  struct node *front;
  struct node *rear;
}dequeue;
typedef struct node{
  int data;
  struct node *prev;
  struct node *next;
}node;

dequeue* createQueue();
void insertRear(dequeue** q,int value);
void insertFront(dequeue** q,int value);
void removeRear(dequeue** q);
void removeFront(dequeue** q);
void display(dequeue* q);
void isEmpty(dequeue** q);

int main(){
  dequeue* q=createQueue();
  while(1){
    system("clear");
      printf("Double Ended Queue implementation using doubly linked list \n");
      printf("-----------------------\n");
  printf("1.Display\n2.InsertRear\n3.InsertFront\n4.RemoveRear\n5.RemoveFront\n6.Exit\n");
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
      insertRear(&q,value);
      printf("Value inserted at rear end.\n");
      break;
    }
    case 3:{
      printf("Enter your value to be inserted: ");
      int value;
      scanf("%d",&value);
      insertFront(&q,value);
      printf("Value inserted at front end.\n");
      break;
    }
    case 4:{
      printf("Removing Element..\n");
      removeRear(&q);
      printf("Element removed at rear end.\n");
      break;
      }

    case 5:{
      printf("Removing Element..\n");
      removeFront(&q);
      printf("Element removed at front end.\n");
      break;

      }
    case 6:{

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

dequeue* createQueue(){
  dequeue* q=malloc(sizeof(dequeue)); 
  q->front=q->rear=NULL;
  return q;
}
void insertRear(dequeue** q,int value){
  if((*q)->front==NULL){
    node* temp=malloc(sizeof(dequeue));
    temp->data=value;
    temp->prev=temp->next=NULL;
    (*q)->front=(*q)->rear=temp;
    return;
  }
    node* temp=malloc(sizeof(dequeue));
    temp->data=value;
    temp->prev=(*q)->rear;
    (*q)->rear->next=temp;

    temp->next=NULL;
    (*q)->rear=temp;
    

}
void insertFront(dequeue** q,int value){
  if((*q)->front==NULL){
    node* temp=malloc(sizeof(dequeue));
    temp->data=value;
    temp->prev=temp->next=NULL;
    (*q)->front=(*q)->rear=temp;
    return;
  }
    node* temp=malloc(sizeof(dequeue));
    temp->data=value;
    temp->prev=NULL;
    (*q)->front->prev=temp;

    temp->next=(*q)->front;
    (*q)->front=temp;
}
void removeRear(dequeue** q){
  if((*q)->front==NULL){
    printf("Queue underflow\n");
    return;
  }
  if((*q)->rear==(*q)->front){
    (*q)->rear=(*q)->front=NULL;
    return;
  }
  node* temp=(*q)->rear;
  (*q)->rear=(*q)->rear->prev;
  free(temp);
  return;

}
void removeFront(dequeue** q){
  if((*q)->front==NULL){
    printf("Queue underflow\n");
    return;
  }
  if((*q)->rear==(*q)->front){
    (*q)->rear=(*q)->front=NULL;
    return;
  }
  node* temp=(*q)->front;
  (*q)->front=(*q)->front->next;
  temp=NULL;
  free(temp);
  return;
}
void display(dequeue* q){
  if(q->front==NULL){
    printf("Empty queue\n");
    return;
  }
  node *temp=(q)->front;
  do{
    printf("%d ",temp->data);
    temp=temp->next;
  }while(temp!=(q)->rear);
  printf("\n");
  return;
}
