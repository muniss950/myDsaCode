#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXQUEUE 100
struct queue
{
 int item[MAXQUEUE];
  int  front,rear;
};
struct queue* createQueue();
int qinsert(struct queue *q, int x,int size);
bool isFull(struct queue *q);
int main(){

}
struct queue* createQueue(){
  struct queue* q;

  q->rear=-1;
  q->front=-1;
  return q;
}
int qinsert(struct queue *q, int x,int size)
{
    if(isFull(q)){
      printf("Queue Overflow..\n");
      return -1;
    }
    else
    {
      q->rear=(q->rear+1)%size;//get the rear index  
      q->item[q->rear]=x;//insert at rear index     
      if(q->front==-1)//if first element          
        q->front=0;// make front point to 0    
    return 1;
    }
}
bool isFull(struct queue *q){
  if((q->rear+1==MAXQUEUE && q->front==0)||(q->rear==(q->front+1)))
  {
    return true;
  }
  return false;
}
