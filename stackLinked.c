
#include <stdio.h>
#include <stdlib.h>

 struct node{
  int data;
  struct node* next;
};
typedef struct node node ;

void displayStack(struct node* head);
void pushStack(struct node** head,int value);
void popStack(struct node** head);

int main(){
  struct node* head=NULL;
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
      displayStack(head);
      break;
    }
    case 2:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      pushStack(&head,value);
      printf("Pushing the value\n");
      break;
    }
    case 3:{
      printf("Popping  Last Element..\n");
      popStack(&head);
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


void displayStack(struct node* head){
  if(head==NULL){
    printf("Empty Stack\n");
    return;
  }
  struct node* temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
void pushStack(struct node** head,int value){
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=*head;
  *head=newNode;
}
void popStack(struct node** head){
  if(*head==NULL){
    printf("Stack Underflow\n");
    return;
  }
  node* temp=*head;
  (*head)=(*head)->next;
  free(temp);
}
