#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct tree{
  int info;
  int used;
}tree;
tree t[MAX];
void init(tree t[MAX]);
int max(int a,int b);
void insert(int value);
int search(int value);
int treeHeight();
void printLevel(int height);
void inOrderDisp();
void postOrderDisp();
void preOrderDisp();
void levelOrderDisp();
void deleteValue(int value);
void printTree();
int main(){
  init(t);
 int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
  for(int i=0;i<7;i++){
    insert(array[i]);
  }
  printTree();
  printf("Binary Search Tree implementation using Node\n");
  
  while(1){
    // system("clear");
      printf("-----------------------\n");
  printf("1.Insert\n2.Search\n3.In-order Display\n4.Pre-order Display\n5.Post-order Display\n6.Tree Height\n7.Level-order display\n8.Exit\n");
  printf("-----------------------\n");
  printf("Give your Choice: ");
  int choice;
  scanf("%d",&choice);
  switch (choice ) {
    case 1:{
      printf("Enter your value to be inserted: ");
      int value;
      scanf("%d",&value);
      insert(value);
      printf("Inserting the value\n");
      break;
    }
    case 2:{
      printf("Enter your value to be searched: ");
      int value;
      scanf("%d",&value);
      printf("Search for the Element..\n");
      search(value);
      break;
    }
    case 3:{
        printf("In-order traversal and display\n");
        inOrderDisp();
        printf("\n");
        break;
      }
    case 4:{
        printf("Pre-order traversal and display\n");
        preOrderDisp();
        printf("\n");
        break;
      }

    case 5:{
        printf("Post-order traversal and display\n");
        postOrderDisp();
        printf("\n");
        break;
      }
    case 6:{
        printf("Tree Height: %d\n",treeHeight());
        break;
    }
    case 7:{
        levelOrderDisp();
        break;
      }
    case 8:{
        goto exitLoop;
        break;
      }
    default:{
      printf("Enter valid choice: \n");
    }
  }
  
  char stop;
      printf("Press any key+Enter to continue...");
      scanf(" %c",&stop);
  }
  exitLoop:;
}
void init(tree t[MAX]){
  for(int i=0;i<MAX;i++){
    t[i].used=0;
  }
}
int max(int a,int b){
  if(a>=b)
    return a;
  return b;
}
void insert(int value){
  int i=0; 
  while(t[i].used!=0){
    if(t[i].info>value){
      i=i*2+2;
      continue;
    }
    if(t[i].info<value){
      i=i*2+1;
      continue;
    }
  }
  t[i].used=1;
  t[i].info=value;
  return;
}
int search(int value){
  return 0;
}
int treeHeight(){
  return 0;

}
void printLevel(int height){
}
void inOrderDisp(){

}

void postOrderDisp(){

}
void preOrderDisp(){

}
void levelOrderDisp(){

}
void deleteValue(int value){

}

void printTree(){

  for(int i=0;i<MAX;i++){
    if(t[i].used!=0){
      printf("%d ->",t[i].info);
    }
    if()
  }
  printf("\n");
}
