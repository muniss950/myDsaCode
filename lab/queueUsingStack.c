


#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};
typedef struct node node ;

typedef struct queueStack{
  node *s1,*s2;
}queue;

void displayStack(struct node* top);
void pushStack(struct node** top,int value);
void popStack(struct node** top);
int peepStack(struct node** top);

void enqueue(queue *q);
int dequeue(queue *q);
void isEmpty(queue *q);
void operate(int choice);
int main(){
  queue *q=malloc(sizeof(queue));
  q->s1=NULL;
  q->s2=NULL;
  int noPos;
  scanf("%d",&noPos);
  for(int i=0;i<noPos;i++){
    int choice;
    scanf("%d",&choice);
  switch (choice) {
      case 1:{
      enqueue(q);
      break;
    }
    case 2:{
      dequeue(q);
      break;
    }
    case 3:{
      isEmpty(q);
      break;
    }
  }
  }
}


void displayStack(struct node* top){
  if(top==NULL){
    printf("Empty Stack\n");
    return;
  }
  struct node* temp=top;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
void pushStack(struct node** top,int value){
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=*top;
  *top=newNode;
}
void popStack(struct node** top){
  if(*top==NULL){
    printf("Stack Underflow\n");
    return;
  }
  node* temp=*top;
  (*top)=(*top)->next;
  free(temp);
}
int peepStack(struct node** top){
  if((*top)==NULL){
    printf("Empty Stack");
    return -1;
  }
  return (*top)->data;
}
void enqueue(queue *q){
  int value;
  scanf("%d",&value);
  while(q->s1!=NULL){
    pushStack(&(q->s2),peepStack(&(q->s1)));
    popStack(&(q->s1));
  }
  pushStack(&(q->s1),value);
  while(q->s2!=NULL){
      pushStack(&(q->s1),peepStack((&q->s2)));
      popStack(&(q->s2));
  }

}
int dequeue(queue *q){
  if(q->s1==NULL){
    return -1;
  }
  int x=peepStack(&(q->s1));
  popStack(&(q->s1));
  printf("%d\n",x);
  return x;
}
void isEmpty(queue *q){
  if(q->s1==NULL){
    printf("True\n");
    return;
  }
  else{
    printf("False\n");
    return;
  }
}
