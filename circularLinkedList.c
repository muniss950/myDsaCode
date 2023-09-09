#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}N;
int checkEmpty(N** last);
void displayList(N* last);
void  createList(int value);
void  insertAtEnd(N** last,int value);
void  insertAtFront(N** last,int value);
void  insertAtPos(N** last,int value,int pos);
void  deleteAtEnd(N** last);
void  deleteAtFront(N** last);
N* deleteAtPos(N** last,int pos);
void bubbleSortList(N** last);
void reverseList(N** last);
int main(){
  N* last=NULL;
  while(1){
  system("clear");
  printf("-----------------------\n");
  printf("Circular Linked List Implementation\n");
  printf("1.Display\n2.CheckEmpty\n3.InsertAtEnd\n4.InsertAtFront\n5.InsertAtPos\n");
  printf("6.DeleteAtEnd\n7.DeleteAtFront\n8.DeleteAtPos\n9.BubbleSortList\n10.ReverseList\n11.Exit");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      displayList(last);
      break;
    }
    case 2:{
        if(checkEmpty(&last)){
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
      insertAtEnd(&last,value);
      printf("Pushing the value\n");
      break;
    }
    case 4:{
      printf("Enter your value to be pushed: ");
      int value;
      scanf("%d",&value);
      insertAtFront(&last,value);
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
      insertAtPos(&last,value,pos);
      printf("Pushing the value\n");
      break;
        
      }


    case 6:{
      printf("Deleting  Last Element..\n");
      deleteAtEnd(&last);
      break;
    }
    case 7:{
      printf("Deleting  Front Element..\n");
      deleteAtFront(&last);
      break;

    }
    case 8:{
      printf("Enter position: ");
      int pos;
      scanf("%d",&pos);
      deleteAtPos(&last,pos);
      printf("Pushing the value\n");
      break;

      }
    case 9:{
      printf("Bubble sorting list...");
      bubbleSortList(&last);
      break;
      }
    case 10:{
        printf("Reversing list...");
        reverseList(&last);
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
int checkEmpty(N** last){
  if((*last)==NULL){
    return 1;
  }
  else{
    return 0;
  }
}
void displayList(N* last){
  if(last==NULL){
    printf("Empty List");
    return;
  }
  else {
    N* temp=last->next;
    do{
      printf("%d ",temp->data);
      temp=temp->next;
    }while(temp!=last->next);
  }
}
void  insertAtFront(N** last,int value){
  if(*last==NULL){
    N* temp=malloc(sizeof(N));
    temp->data=value;
    temp->next=temp;
    *last=temp;
    return;
  }
  else{
    N* temp=malloc(sizeof(N));
    temp->data=value;
    temp->next=(*last)->next;
    (*last)->next=temp;   
  }

}
void insertAtEnd(N** last,int value){
  if(*last==NULL){
    N* temp=malloc(sizeof(N));
    temp->data=value;
    temp->next=temp;
    *last=temp;
    return;
  }
  else{
    N* temp=malloc(sizeof(N));
    temp->data=value;
    temp->next=(*last)->next;
    (*last)->next=temp;
    *last=temp;
    
  }  
}

void  deleteAtFront(N** last){
  if(*last==NULL){
    printf("Empty List ");
    return;
  }
  if(*last==(*last)->next){
    free(*last);
    return;
  }
  N* temp=(*last)->next;
  (*last)->next=temp->next;
  free(temp);
}
void bubbleSortList(N** last){

}
void reverseList(N** last){

}
void  deleteAtEnd(N** last){
  
}
N* deleteAtPos(N** last,int pos){
  return *last;
}
void insertAtPos(N** last,int value,int pos){

}
