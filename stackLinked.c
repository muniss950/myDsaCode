
#include <stdio.h>
#include <stdlib.h>

 struct node{
  int data;
  struct node* next;
};
typedef struct node node ;

void displayStack(struct node* top);
void pushStack(struct node** top,int value);
void popStack(struct node** top);

int main(){
  struct node* top=NULL;
  printf("Stack implementation using Node\n");

  while(1){
      printf("-----------------------\n");
  printf("1.Display\n2.Push\n3.Pop\n4.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      displayStack(top);
      break;
    }
    case 2:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      pushStack(&top,value);
      printf("Pushing the value\n");
      break;
    }
    case 3:{
      printf("Popping  Last Element..\n");
      popStack(&top);
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

  }
  exitLoop:;
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
