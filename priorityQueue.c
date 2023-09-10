#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
typedef struct node{
  int data;
  int pty;
  struct node* next;
}queue;


void insert(queue** q,int x,int pty);
void delete(queue** q);
void display(queue *q);

int main(){
  queue* q=NULL;

  while(1){
    system("clear");
  printf("Ascending Priority queue implementation using Node\n");
      printf("-----------------------\n");
  printf("1.Display\n2.Insert\n3.Remove\n4.Exit");
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
      printf("Enter your Priority of value to be inserted: ");
      int pty;
      scanf("%d",&pty);
      insert(&q,value,pty);
      printf("Value inserted\n");
      break;
    }
    case 3:{
      printf("Deleting Element with highest Priority..\n");
      delete(&q);
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

void insert(queue** q,int x,int pty){
  queue* temp=(*q);
  if(temp==NULL){
    queue* newNode=malloc(sizeof(queue));
    newNode->data=x;
    newNode->pty=pty;
    newNode->next=NULL;
    (*q)=newNode;
    return;
  }
  while(temp==NULL&& pty<=temp->pty ){
    temp=temp->next;
  }
    queue* newNode=malloc(sizeof(queue));
    newNode->data=x;
    newNode->pty=pty;
    newNode->next=temp->next;
    temp->next=newNode;
}
void delete(queue** q){
  if((*q)==NULL){
    printf("Underflow\n");
    return;
  }
  queue* temp=*q;
  (*q)=(*q)->next;
  free(temp);
}
void display(queue *q){
  if(q==NULL){
    printf("Empty queue\n");
    return;
  }
  printf("Data,Priority\n\n");
  while(q!=NULL){
    printf("%d %d \n",q->data,q->pty);
    q=q->next;
  }
}
