#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

node* head=NULL;


void displayList();
void insertAtEnd(int value);

int main(){
  insertAtEnd(3);
  insertAtEnd(31);
  insertAtEnd(2);
  displayList();
}

void displayList(){
  while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;
  }
}

void insertAtEnd(int value){
  if(head==NULL){
    head=realloc(head,sizeof(node));
    head->data=value;
    head->next=NULL;
    return;
  }
  while(head->next!=NULL){
    head=head->next;
  }
  node* newNode=malloc(sizeof(node));
  newNode->data=value;
  newNode->next=NULL;
  head->next=newNode;
  return;
}

