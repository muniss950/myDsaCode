
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
typedef struct binaryNode{
  int data;
  struct binaryNode *left,*right;
  int rthread; 
}node;

void setLeft(node* q,int e);
void setRight(node* q,int e);
int max(int a,int b);
node* newNode(int value);
void insert(node** root,int value);
node* search(node* root,int value);
int treeHeight(node* root);
void printLevel(node * root,int height);
void inOrderDisp(node* root);
void postOrderDisp(node* root);
void preOrderDisp(node* root);
void levelOrderDisp(node* root);
void deleteValue(node *root,int value);
int main(){
  node* root=NULL;
  int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
  for(int i=0;i<7;i++){
    insert(&root,array[i]);
  }
  printf("Right-in ThreadedBinary Search Tree implementation using Node\n");
  
  while(1){
    system("clear");
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
      insert(&root,value);
      printf("Inserting the value\n");
      break;
    }
    case 2:{
      printf("Enter your value to be searched: ");
      int value;
      scanf("%d",&value);
      printf("Search for the Element..\n");
      search(root,value);
      break;
    }
    case 3:{
        printf("In-order traversal and display\n");
        inOrderDisp(root);
        printf("\n");
        break;
      }
    case 4:{
        printf("Pre-order traversal and display\n");
        preOrderDisp(root);
        printf("\n");
        break;
      }

    case 5:{
        printf("Post-order traversal and display\n");
        postOrderDisp(root);
        printf("\n");
        break;
      }
    case 6:{
        printf("Tree Height: %d\n",treeHeight(root));
        break;
    }
    case 7:{
        levelOrderDisp(root);
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
node* newNode(int value){
  node* temp=malloc(sizeof(node));
  temp->data=value;
  temp->left=temp->right=NULL;
  temp->rthread=1;
  return temp;
}

void setLeft(node* q,int data){
  node* temp=newNode(data);
  q->left=temp;
  temp->right=q;
}

void setRight(node* q,int data){
  node* temp=newNode(data);
  temp->right=q->right;
  q->right=temp;
  q->rthread=0;
}

void insert(node** root,int data){
    node *current;
    node *parent;

   //if tree is empty
   if(*root == NULL) {
      *root=newNode(data);
      return;
   } else {
      current = *root;
      parent = NULL;
      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->left;

            //insert to the left
            if(current == NULL) {
               parent->left = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->right;

            //insert to the right
            if(current == NULL) {
               parent->right= tempNode;
               return;
            }
         }
      }
   }
}
node* search(node* root,int value){
  if(root==NULL){
    printf("Value not found in tree\n");
    return NULL;
  }
  if(root->data==value){
    return root;
  }
  if((root->data)>value){
    return search(root->left,value);
  }
  if((root->data)<value){
    return search(root->right,value);
  }
  return NULL;
}
void inOrderDisp(node* root){
  if(root!=NULL){
  inOrderDisp(root->left);
  printf("%d ",root->data);
  inOrderDisp(root->right);
  }
}
void postOrderDisp(node* root){
  if(root!=NULL){
  postOrderDisp(root->left);
  postOrderDisp(root->right);
  printf("%d ",root->data);
  }
}
void preOrderDisp(node* root){
  if(root!=NULL){
  printf("%d ",root->data);
  preOrderDisp(root->left);
  preOrderDisp(root->right);
  }
}
int treeHeight(node* root) {
    if (root == NULL) 
        return 0;
    else {
        // Find the height of left, right subtrees
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        
        // Find max(subtree_height) + 1 to get the height of the tree
        return max(leftHeight, rightHeight) + 1;
  }
}
int max(int a,int b ){
  if(a>=b){
    return a;
  }
  else 
    return b;
}
void levelOrderDisp(node* root){
  int height=treeHeight(root);
  for(int i=0;i<height+1;i++){
    // printf("Level: %d\n" 
    for (int j = 1; j <= height-i; j++){  
      printf ("  ");   
    }
    printLevel(root,i);
    printf("\n");
  }
}
void printLevel(node * root,int height){
  if(root==NULL){
    return;
  }
  if(height==0){
    printf("%d ",root->data);
    return;
  }
  else {
    printLevel(root->left,height-1);
    printLevel(root->right,height-1);
  }
}

void deleteValue(node *root,int value){
  node* temp=search(root,value);
}
