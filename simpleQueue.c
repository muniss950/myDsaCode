#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct queue{
  int array[MAX];
  int front,rear;
}queue;

queue* createQueue();
void insert(queue** q,int value);
void removeElem(queue** q);
void display(queue* q);
void emptyQueue(queue** q);
int main(){

  queue* q=createQueue();
  while(1){
    system("clear");
      printf("Simple Queue implementation using Struct \n");
      printf("-----------------------\n");
  printf("1.Display\n2.Insert\n3.Remove\n4.Empty\n5.Exit");
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
      removeElem(&q);
      printf("Element removed\n");
      break;
    }
    case 4:{
        emptyQueue(&q);
        printf("The queue is emptied.\n");
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
  q->front=-1;
  q->rear=-1;
  return q;
}
void insert(queue** q,int value){
  if((*q)->rear>=MAX){
    printf("Queue overflow");
    return;
  }
  ((*q)->array)[(++(*q)->rear)]=value;
  if((*q)->front==-1){
    (*q)->front=0;
  }
  return;
}
void removeElem(queue** q){
  if((*q)->rear==-1){
    printf("Queue underflow");
    return;
  }
  (*q)->rear--;
  if((*q)->rear==-1){
    (*q)->front=-1;
  }
  return;
}
void display(queue* q){
  if((q)->rear==-1){
    printf("Empty queue\n");
    return;
  }
  for(int i=(q)->front;i<(q)->rear+1;i++){
    printf("%d ",(q)->array[i]);
  }
  printf("\n");
  return;
}
void emptyQueue(queue** q){
  (*q)->front=(*q)->rear=-1;
}
