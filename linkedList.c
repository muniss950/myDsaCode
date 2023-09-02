#include <stdio.h>
#include <stdlib.h>

 struct node{
  int data;
  struct node* next;
};


struct node* createList();
void displayList(struct node* head);
void insertAtEnd(struct node* head,int value);
void insertAtFront(struct node** head,int value);

int main(){
  struct node* head=createList();
  insertAtEnd(head,3);
  insertAtEnd(head,31);
  // insertAtFront(&head,2);
  displayList(head);
}

struct node* createList(){
  struct node* head=NULL;
  return head;
}

void displayList(struct node* head){
  if(head==NULL){
    printf("Empty List\n");
    return;
  }
  struct node* temp=head;
  while(temp!=NULL){
    printf("%i ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void insertAtEnd(struct node* head,int value){
  if(head==NULL){
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    head=newNode;
    return;
  }
  struct node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=NULL;
  temp->next=newNode;
  return;
}
void insertAtFront(struct node** head,int value){
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=*head;
  *head=newNode;
}

