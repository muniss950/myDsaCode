#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXQUEUE 5
typedef struct queue
{
 int item[MAXQUEUE];
  int  front,rear;
}queue;
struct queue* createQueue();
void enqueue(struct queue *q, int x);
bool isFull(struct queue *q);
void display(queue *q);
void dequeue(struct queue *q);
int main(){
  queue* q=createQueue();
  for(int i=0;i<5;i++){
    enqueue(q,i);
  }
  while(1){
    system("clear");
      printf("Double Ended Queue implementation using doubly linked list \n");
      printf("-----------------------\n");
  printf("1.Display\n2.Enqueue\n3.Dequeue\n4.Exit\n");
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
      enqueue(q,value);
      break;
    }
    case 3:{
      printf("Removing Element..\n");
      dequeue(q);
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
struct queue* createQueue(){
  struct queue* q=malloc(sizeof(queue));

  q->rear=-1;
  q->front=-1;
  return q;
}
void enqueue(struct queue *q, int x)
{
    if(isFull(q)){
      printf("Queue Overflow..\n");
      return ;
    }
    else if(q->rear==MAXQUEUE-1){
      q->rear=0;
      q->item[q->rear]=x;
      return;
    }
    else
    {
      q->item[++q->rear]=x;//insert at rear index     
      if(q->front==-1)//if first element          
        q->front=0;// make front point to 0    
    return ;
    }
}
bool isFull(struct queue *q){
  if((q->rear+1==MAXQUEUE && q->front==0)||(q->rear+1==q->front && q->front>0))
  {
    return true;
  }
  return false;
}
void display(queue *q){
  int temp=q->front;
  if(temp==-1){
    printf("Empty queue\n");
    return;
  }
  printf("%d %d\n",q->front,q->rear);
  do{
    printf("%d ",q->item[temp]);
    if(temp==q->rear){
      break;
    }
    if((temp++)==MAXQUEUE-1){
        temp=0;
    }
  }while(true);
  printf("\n");

}
void dequeue(struct queue *q){
  q->item[q->front++]=-1;
  if(q->front==MAXQUEUE-1)
    q->front=q->rear=0;
}
