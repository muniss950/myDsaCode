#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 1000
struct node{
  char data;
  struct node* next;
};
typedef struct node node ;

void displayStack(struct node* top);
void pushStack(struct node** top,char value);
void popStack(struct node** top);
int peepStack(struct node** top);
int precedence(char ch);
void infixToPrefix(char* expression);
bool checkIfOperand(char ch);
bool greaterPrecedence(char a,char b);
int main(){
  struct node* top=NULL;
  printf("Infix conversions using stack\n");

  while(1){
    system("clear");
      printf("-----------------------\n");
  printf("1.Postfix\n2.Prefix\n3.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      printf("Enter your expression to be converted: ");
      char exp[MAX];
      scanf("%s",exp);
      printf("test");
      infixToPrefix(exp);
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
void pushStack(struct node** top,char value){
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
    return -1;
  }
  else{
    return (*top)->data;
  }
}
int precedence(char ch){
  switch (ch) {
    case '+':
    case '-':
      return 1;
      break;
    case '*':
    case '/':
      return 2;
      break;
    case ')':
    case ']':
    case '}':
      return 3;
      break;
    case '(':
    case '{':
    case '[':
      return 0;
      break;
    default:
      return -1;
      break;
  
  }
}
bool greaterPrecedence(char a,char b){
  return (precedence(a)>precedence(b));
}
bool checkIfOperand(char ch){
  return (ch>='0' && ch<='9'|| ch>='a' && ch<='z'|| ch>='A' &&ch<='Z');
}

void infixToPrefix(char* exp){
  struct node* top=NULL;
  char postStr[MAX];
  int j=0; // index for poststr
  int size=strlen(exp);
  for(int i=0;i<size;i++){
    if(checkIfOperand(exp[i])){
      postStr[j++]=exp[i];
    }
    else{
      while(greaterPrecedence(peepStack(&top),exp[i])&& peepStack(&top)!='('){
        if(peepStack(&top)!=')')
        postStr[j++]=peepStack(&top);
        popStack(&top);
      } 
      if(peepStack(&top)!=')')
      pushStack(&top,exp[i]);
    }
  }
  while(top!=NULL){
    if(peepStack(&top)!=')' && peepStack(&top)!='('){
      postStr[j++]=peepStack(&top);
    }
      popStack(&top);
  }
  postStr[j]='\0';
  printf("%s",postStr);
  return;
}
