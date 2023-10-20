#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

int solve(node *node);
node *buildBinaryTree(int *arr, int i, int n);
int max(int a, int b); 
int getHeight(node *node); 

int main() {
  int size;
  scanf("%d", &size);

  int *arr = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  node *root = buildBinaryTree(arr, 0, size);
  int dia = solve(root);
  printf("%d", dia);

  return 0;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int getHeight(node *node) {
  if (node == NULL) {
    return 0;
  }

  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  return max(leftHeight, rightHeight) + 1;
}

int solve(node *node) {
  if (node == NULL) {
    return 0;
  }


  int leftH = getHeight(node->left);
  int rightH = getHeight(node->right);
  
  int leftD = solve(node->left);
  int rightD = solve(node->right);
  return max(max(leftD, rightD), leftH + rightH + 1);
}

node *buildBinaryTree(int *arr, int i, int n) {
  if (i >= n || arr[i] == -1) {
    return NULL;
  }

  node *temp = (node *)malloc(sizeof(node));
  temp->data = arr[i];
  temp->left = buildBinaryTree(arr, 2 * i + 1, n);
  temp->right = buildBinaryTree(arr, 2 * i + 2, n);
  return temp;
}

