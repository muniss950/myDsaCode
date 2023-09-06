#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}N;

void displayList(N* last);
void  createList(int value);
void  insertAtEnd(N** last,int value);
void  insertAtFront(N** last,int value);
void  insertAtPos(N** last,int value,int pos);
void  deleteAtEnd(N** last);
void  deleteAtFront(N** last);
N* deleteAtPos(N** last,int pos);

int main(){
  N* last=NULL;
  insertAtFront(&last, 3);
  insertAtFront(&last, 3);
  insertAtFront(&last, 3);
  displayList(last);
  printf("\n");
  deleteAtFront(&last);
  displayList(last);
  printf("\n");
  deleteAtFront(&last);
  printf("\n");
  displayList(last);
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
