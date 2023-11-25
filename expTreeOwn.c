#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}node;

int stack[MAX];

node* createExpTree(char exp[MAX]);
void printInorder(node* root);
void evalTree(node* root);

int main(){
  char exp[MAX]; 
  printf("Enter the expression here: ");
  
}
