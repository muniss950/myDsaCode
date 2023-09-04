#include <stdio.h>
#include <stdlib.h>


 struct node{
  int data;
  struct node* next;
};
typedef struct node node ;

void displayList(struct node* head);
void insertAtEnd(struct node** head,int value);
void insertAtFront(struct node** head,int value);
void insertAtPos(struct node** head,int value,int pos);
void bubbleSortList(struct node **head);
void reverseList(node** head);
void deleteAtFront(struct node** head);
void deleteAtEnd(struct node** head);
void deleteAtPos(struct node** head,int pos);
int main(){
  struct node* head=NULL;
  insertAtEnd(&head,2);
  insertAtEnd(&head,3);
  insertAtFront(&head,4);
  insertAtFront(&head,5);
  insertAtFront(&head,5);
  displayList(head);
  // bubbleSortList(&head);
  // displayList(head);
  reverseList(&head);
  displayList(head);
}


void displayList(struct node* head){
  if(head==NULL){
    printf("Empty List\n");
    return;
  }
  struct node* temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void insertAtEnd(struct node** head,int value){
  if(*head==NULL){
    // printf("lol");
    *head=malloc((sizeof(struct node)));
    (*head)->data=value;
    (*head)->next=NULL;
    return;
  }
  struct node* temp=*head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=NULL;
  temp->next=newNode;
  // displayList(head);
  return;
}
void insertAtFront(struct node** head,int value){
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=*head;
  *head=newNode;
}
void reverseList(node **head){
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void bubbleSortList(struct node **head){
  if(*head==NULL){
    return;
  }  
  node* start=*head;
  node* temp=*head;
  while(start->next!=NULL){
    while(temp!=NULL){
      int nowData=temp->data;
      int startData=start->data;
      if(startData>nowData){
        int storeData=nowData;
        temp->data=start->data;
        start->data=nowData;
      }
      temp=temp->next;
    }
    start=start->next;
    temp=start;
  }
  return;
}
