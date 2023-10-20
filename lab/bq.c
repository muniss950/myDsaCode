#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int data);
struct TreeNode* buildTreeFromLevelOrder(int levelOrder[], int size, int index); 
int countLeaves(struct TreeNode* root); 
int main() {
    int levelOrder[1000]; 
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &levelOrder[i]);
    }
    struct TreeNode* root = buildTreeFromLevelOrder(levelOrder, size, 0);
    int leafCount = countLeaves(root);
    printf("%d\n", leafCount);
    return 0;
}
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct TreeNode* buildTreeFromLevelOrder(int levelOrder[], int size, int index) {
    if (index < size) {
        if (levelOrder[index] == -1) {
            return NULL;
        }

        struct TreeNode* root = createNode(levelOrder[index]);
        root->left = buildTreeFromLevelOrder(levelOrder, size, 2 * index + 1);
        root->right = buildTreeFromLevelOrder(levelOrder, size, 2 * index + 2);

        return root;
    }

    return NULL;
}
int countLeaves(struct TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        else{
            return countLeaves(root->right)+countLeaves(root->left);
        }
}
