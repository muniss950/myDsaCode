
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* prev;
};
typedef struct node node ;
int checkEmpty(struct node** head);
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
  while(1){
  system("clear");
  printf("-----------------------\n");
  printf("Doubly Linked List Implementation\n");
  printf("1.Display\n2.CheckEmpty\n3.InsertAtEnd\n4.InsertAtFront\n5.InsertAtPos\n");
  printf("6.DeleteAtEnd\n7.DeleteAtFront\n8.DeleteAtPos\n9.BubbleSortList\n10.ReverseList\n11.Exit");
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
        printf("Reversing list...");
        reverseList(&head);
        printf("The list reversed");
        break;
      }
    case 11:{
        goto exitLoop;
        break;

      }
    default:{
      printf("Enter valid choice: \n");
      break;
    }

  }
  char stop;
      printf("Press any key to continue...");
      scanf(" %c",&stop);


  }
  exitLoop:;
}

int checkEmpty(struct node** head){
  if((*head)==NULL){
    return 1;
  }
  else{
    return 0;
  }
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
    (*head)->prev=NULL;
    return;
  }
  struct node* temp=*head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=NULL;
  newNode->prev=temp;
  temp->next=newNode;
  // displayList(head);
  return;
}
void insertAtFront(struct node** head,int value){
  struct node* newNode=malloc(sizeof(struct node));
  newNode->data=value;
  newNode->next=*head;
  newNode->prev=NULL;
  (*head)->prev=newNode;
  *head=newNode;
}
void reverseList(node **head){
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev=next;
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
void deleteAtEnd(struct node** head){

}
void deleteAtFront(struct node** head){

}
void deleteAtPos(struct node** head,int pos){

}
void insertAtPos(struct node** head,int value,int pos){

}
