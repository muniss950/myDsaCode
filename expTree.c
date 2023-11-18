#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a structure for a node in the expression tree
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build an expression tree from a postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100];  // Assuming the postfix expression is not too long
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; ++i) {
        struct Node* newNode = createNode(postfix[i]);

        if (isdigit(postfix[i])) {
            stack[++top] = newNode;
        } else {
            // Pop two operands from the stack
            struct Node* operand2 = stack[top--];
            struct Node* operand1 = stack[top--];

            // Make the current operator as the root and push it onto the stack
            newNode->left = operand1;
            newNode->right = operand2;
            stack[++top] = newNode;
        }
    }

    // The final expression tree is at the top of the stack
    return stack[top];
}

// Function to evaluate the expression tree
int evaluateExpressionTree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (isdigit(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

// Function to print the infix expression by inorder traversal of the expression tree
void printInfix(struct Node* root) {
    if (root != NULL) {
        if (isdigit(root->data)) {
            printf("%c", root->data);
        } else {
            printf("(");
            printInfix(root->left);
            printf("%c", root->data);
            printInfix(root->right);
            printf(")");
        }
    }
}

int main() {
    char postfix[] = "34*2+";

    struct Node* root = buildExpressionTree(postfix);

    printf("Infix Expression: ");
    printInfix(root);

    printf("\nResult: %d\n", evaluateExpressionTree(root));

    return 0;
}
