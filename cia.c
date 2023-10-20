#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *buildBinaryTree(int *arr, int i, int n); 
node *solve(node *root, int a, int b); 

int main() {
  int n;
  scanf("%d", &n);


  int *arr = (int *)malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int n1, n2;

  scanf("%d %d", &n1, &n2);

  node *root = buildBinaryTree(arr, 0, n);
    node *lcaNode = solve(root, n1, n2);

  printf("%d", lcaNode->data);

  return 0;
}

node *buildBinaryTree(int *arr, int i, int n) {
  if (i >= n || arr[i] == -1) {
    return NULL;
  }

  node *temp =(node*)malloc(sizeof(node));
  temp->data = arr[i];
  temp->left = buildBinaryTree(arr, 2 * i + 1, n);
  temp->right = buildBinaryTree(arr, 2 * i + 2, n);
  return temp;
}

node *solve(node *root, int a, int b) {
  if (root == NULL) {
    return NULL;
  }

  if (root->data ==a || root->data ==b) {
    return root;
  }

  node *leftLCA = solve(root->left, a, b);
  node *rightLCA = solve(root->right, a, b);

  if (leftLCA && rightLCA) {
    return root;
  } else if (leftLCA) {
    return leftLCA;
  } else {
    return rightLCA;
  }
}

