#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct StructElement 
{
    char data[MAX];
    int top;
} Stack;

void initializeStack(Stack* stack) ;
void pushStack(Stack* stack, char element);
char popStack(Stack* stack) ;
char peekStack(Stack* stack) ;
int isOperator(char ch) ;
int precedence(char operator) ;
void convertInfixToPostfix(char* infix, char* postfix) ;

int main() 
{
    char infix[MAX];
    char postfix[MAX];

    scanf("%s", infix);

    convertInfixToPostfix(infix, postfix);

    printf("%s", postfix);

    return 0;
}


void initializeStack(Stack* stack) 
{
    stack->top = -1;
}

char popStack(Stack* stack) 
{
    if (stack->top == -1) 
    {
        return '\0';
    }
    return stack->data[stack->top--];
}
void pushStack(Stack* stack, char element) {
    stack->data[++stack->top] = element;
}

char peekStack(Stack* stack) 
{
    if (stack->top == -1) 
    {
        return '\0';
    }
    return stack->data[stack->top];
}

int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char operator) 
{
    if (operator == '+' || operator == '-') 
    {
        return 1;
    } else if (operator == '*' || operator == '/') 
    {
        return 2;
    }
    return 0;
}

void convertInfixToPostfix(char* infix, char* postfix) 
{
    Stack operatorStack;
    initializeStack(&operatorStack);
    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++)
    {
        char currentChar = infix[i];

        if (isOperator(currentChar)) 
        {
          while (precedence(currentChar) <= precedence(peekStack(&operatorStack)) && peekStack(&operatorStack) != '(') 
            {
                postfix[postfixIndex++] = popStack(&operatorStack);
            }
          pushStack(&operatorStack, currentChar);
        } 
        else if (currentChar == '(') 
        {
            pushStack(&operatorStack, currentChar);
        } 
        else if (currentChar == ')') 
        {
            while (peekStack(&operatorStack) != '(') 
            {
                postfix[postfixIndex++] = popStack(&operatorStack);
            }
            popStack(&operatorStack);
        } 
        else 
        {
            postfix[postfixIndex++] = currentChar;
        }
    }

    while (peekStack(&operatorStack) != '\0')
    {
        postfix[postfixIndex++] = popStack(&operatorStack);
    }

  postfix[postfixIndex] = '\0';
}

