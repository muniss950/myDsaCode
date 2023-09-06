
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  int top;
  int data;
  struct node* next;
};
typedef struct node node ;

int isEmpty(struct node** top);
void displayStack(struct node* top);
void pushStack(struct node** top,int value);
int popStack(struct node** top);
int peekStack(struct node** top);
int precedence(char operator);
int checkOperand(char operch);
int match(char a,char b);
int infixToPostFix(char* expression);
int main(){
char expression[] = "((p+(q*r))-s)"; 
    infixToPostFix(expression); 
    return 0; 

}

int isEmpty(struct node** top){
  return ((*top)==NULL);
}

int precedence(char operator){
  switch (operator) {
    case '^':{
      return 3;
      break;
    }
    case ('*'):
    case ('/'):{
      return 2;
      break;
    }
    case '+':
    case '-':{
      return 1;
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
  if((*top)->next==NULL){
    int data=(*top)->data;
    free(*top);
    return data;
  }   
  node* temp=*top;
  (*top)=(*top)->next;
  int data=temp->data;
  free(temp);
  return data;
}

int peekStack(struct node** top){
  return (*top)->data;
}
int checkIfOperand(char operch){
  return (operch>='a'&& operch<='z'||operch>='A'&&operch<='B');
}

int match(char a,char b){
  if(a=='('&& b==')'){
    return 1;
  }else if(a=='['&& b==']'){
      return 1;
  }else if(a=='{'&& b=='}' ){
        return 1;
  }else{
    return 1;
  }
}

int infixToPostFix(char* expression){
  int i, j;
    struct node* top;
    for (i = 0, j = -1; expression[i]; ++i)
    { 
      if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i];
      else if (expression[i] == '(')
            pushStack(&top, expression[i]);
      else if (expression[i] == ')') 
        { 
            while (!isEmpty(&top) && peekStack(&top) != '(')
                expression[++j] = popStack(&top); 
            if (!isEmpty(&top) && peekStack(&top) != '(') 
                return -1; 
            else
                popStack(&top); 
        } 
      else 
        { 
            while (!isEmpty(&top) && precedence(expression[i]) <= precedence(peekStack(&top))) 
                expression[++j] = popStack(&top); 
            pushStack(&top, expression[i]); 
        } 
    } 
     while (!isEmpty(&top)) 
        expression[++j] = popStack(&top); 
    expression[++j] = '\0'; 
    printf( "%s", expression);

}
