
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};
typedef struct node node ;

void displayStack(struct node* top);
void pushStack(struct node** top,int value);
int popStack(struct node** top);
int precedence(char operator);

int main(){

}


int precedence(char operator){
  switch (operator) {
    case ')':{
      return 4;
      break;
    }
    case '^':{
      return 3;
      break;
    }
    case ('*'):{
      return 2;
      break;
    }
    case ('/'):{
      return 2;
      break;
    }
    case '+':{
      return 1;
      break;
    }
    case '-':{
      return 1;
      break;
    }
    case '(':{
      return 0;
      break;
    }
    default:
      return -1;
  };
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
int popStack(struct node** top){
  if(*top==NULL){
    printf("Stack Underflow\n");
    return -1;
  }
  node* temp=*top;
  (*top)=(*top)->next;
  int data=temp->data;
  free(temp);
  return data;
}
