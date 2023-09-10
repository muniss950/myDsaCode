#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int stackArray[MAX];
int top=-1;

void display();
void push(int value);
void popStack();

int main(){
  while(1){
    system("clear");
      printf("-----------------------\n");
  printf("Stack implementation using array\n");
  printf("1.Display\n2.Push\n3.Pop\n4.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      display();
      break;
    }
    case 2:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      push(value);
      printf("Pushing the value\n");
      break;
    }
    case 3:{
      printf("Popping  Last Element..\n");
      popStack();
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
      printf("Press any key to continue...");
      scanf(" %c",&stop);

  }
  exitLoop:;
}
void display(){
  if(top==-1){
    printf("Stack Empty ");
  }
  for(int i=0;i<top+1;i++){
    printf("%d ",stackArray[i]);
  }
  // printf("\n");
}
void push(int value){
  if(top==MAX){
    printf("Stack Overflow ");
    return;
  }
  top++;
  stackArray[top]=value;
}

void popStack(){
  if(top==-1){
    printf("Stack Underflow ");
    return;
  }
  top--;
}
