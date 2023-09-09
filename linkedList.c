#include <stdio.h>
#include <stdlib.h>


struct node{
  int data;
  struct node* next;
};
struct head{
  struct node* next;
};
typedef struct node node ;
typedef struct head head ;
int checkEmpty(head**head);
void displayList(head* head);
void insertAtEnd(head** head,int value);
void insertAtFront(head** head,int value);
void insertAtPos(head** head,int value,int pos);
void bubbleSortList(head **head);
void reverseList(head** head);
void deleteAtFront(head** head);
void deleteAtEnd(head** head);
void deleteAtPos(head** head,int pos);

int main(){
  head *head=NULL;
  while(1){
      printf("-----------------------\n");
  printf("Linked List Implementation\n");
  printf("1.Display\n2.CheckEmpty\n3.InsertAtEnd\n4.InsertAtFront\n5.InsertAtPos\n");
  printf("6.DeleteAtEnd\n7.DeleteAtFront\n8.deleteAtPos\n9.BubbleSortList\n10.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      displayList(head);
      break;
    }
    case 2:{
        if(checkEmpty(&head)){
          printf("The list is empty");
        }
        else{
          printf("The list is not empty");
        }
        break;
      }
    case 3:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      insertAtEnd(&head,value);
      printf("Pushing the value\n");
      break;
    }
    case 4:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      insertAtFront(&head,value);
      printf("Pushing the value\n");
      break;

      }
    case 5:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      printf("Enter position: ");
      int pos;
      scanf("%d",&pos);
      insertAtPos(&head,value,pos);
      printf("Pushing the value\n");
      break;
        
      }


    case 6:{
      printf("Deleting  Last Element..\n");
      deleteAtEnd(&head);
      break;
    }
    case 7:{
      printf("Deleting  Front Element..\n");
      deleteAtFront(&head);
      break;

    }
    case 8:{
      printf("Enter position: ");
      int pos;
      scanf("%d",&pos);
      deleteAtPos(&head,pos);
      printf("Pushing the value\n");
      break;

      }
    case 9:{
      printf("Bubble sorting list...");
      bubbleSortList(&head);
      break;
      }
    case 10:{
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

int checkEmpty(head**head){
  if((*head)==NULL ||(*head)->next==NULL){

    return 1;
  }
  else return 0;
}


void displayList(head* head){
  if(checkEmpty(&head)){
    printf("Empty List\n");
    return;
  }
  struct node* temp=head->next;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void insertAtEnd(head** head,int value){
  if(checkEmpty(head)){
    // printf("lol");
    *head=malloc(sizeof(struct head));
    node* newNode;
    newNode=malloc((sizeof(struct node)));
    (newNode)->data=value;
    (newNode)->next=NULL;
    (*head)->next=newNode;
    return;
  }
  struct node* temp=(*head)->next;
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
void insertAtFront(head** head,int value){
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=(*head)->next;
  (*head)->next=newNode;
}
void reverseList(head **head){
    
    node* prev = NULL;
    node* current = (*head)->next;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head)->next = prev;
}
void bubbleSortList(head **head){
  if(*head==NULL){
    return;
  }  
  node* start=(*head)->next;
  node* temp=(*head)->next;
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

void deleteAtFront(head** head){
  if(checkEmpty(head)){
    printf("Empty List");
    return;
  }
  node* temp=(*head)->next;
  (*head)->next=(*head)->next->next;
  free(temp);
}
void deleteAtEnd(head** head){
  if(checkEmpty(head)){
    printf("Empty List ");
    return;
  }
  node* temp=(*head)->next;
  node* prev=NULL;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }
  if(prev!=NULL){
    prev->next=NULL;
  }
  if((*head)->next==(temp)){
    (*head)->next=NULL;
  }
  free(temp);
}
void insertAtPos(head** head,int value,int pos){
  return;
}
void deleteAtPos(head** head,int pos){
  return;
}
