

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

  struct node* top=NULL;
void displayStack(struct node* top);
void pushStack(struct node** top,char value);
char popStack(struct node** top);
char peepStack(struct node** top);
void checkMatching(char* exp);
bool bracketCheck(char a,char b);
int main(){
  printf("Checking Parenthesis Matching using Stack implementation using Node\n");

  while(1){
    system("clear");
      printf("-----------------------\n");
  printf("1.Check\n2.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      printf("Enter your expression to be checked: ");
      char  exp[MAX];
      scanf("%s",exp);
      checkMatching(exp);
      break;
    }
    case 2:{
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
char popStack(struct node** top){
  if(*top==NULL){
    // printf("Stack Underflow\n");
    return '\0';
  }
  node* temp=*top;
  char value=temp->data;
  
  (*top)=(*top)->next;
  free(temp);
  return value;
}
char peepStack(struct node** top){
  if((*top)==NULL){
    printf("Empty Stack");
    return -1;
  }
  return (*top)->data;
}
bool bracketCheck(char a,char b){
  return (a=='('&& b==')'|| a=='{'&& b=='}' || a=='['&& b==']');
}
bool isOpenBracket(char a){
  return (a=='('|| a=='{'|| a=='[');
}
void checkMatching(char * exp){
  struct node* top=NULL;
  // printf("test");
  int check=0;
  int size=strlen(exp);
  for(int i=0;i<size;i++){
    if(isOpenBracket(exp[i])){
      check++;
      pushStack(&top,exp[i]);
      continue;
    }
    if(!bracketCheck(popStack(&top),exp[i])){
      printf("Not Matching\n");
      return;
    }
    else
      check--;
  }
  if(!check)
  printf("Bracket Matching\n");
  else
   printf("Not Matching\n");
  return;
}
