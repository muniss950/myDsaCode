#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}N;

void displayList(N* last);
N* createList(int value);
N* insertAtEnd(N** last,int value);
void  insertAtFront(N** last,int value);
N* insertAtPos(N** last,int value,int pos);
N* deleteAtEnd(N** last);
N* deleteAtFront(N** last);
N* deleteAtPos(N** last,int pos);

int main(){

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
