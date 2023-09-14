// C program to evaluate value of a postfix expression
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack type
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array
		= (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->array)
		return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

int isDigit(char ch){
  if(ch>='0' && ch<='9'){
    return 1;
  }
  else{
    return 0;
  }
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

// The main function that returns value
int evaluatePrefix(char* prefixExp) {
   
   struct Stack operendStack;
   int size = strlen(prefixExp);
   
   for (int i = size; i >= 0; i--) {

      if (isDigit(prefixExp[i]))
         push(&operendStack,prefixExp[i] - '0');
      else {
         int o1 = operendStack.top;
         pop(&operendStack);
         int o2 = operendStack.top;
         pop(&operendStack);
         if( prefixExp[i] == '+')
            push(&operendStack,o1 + o2);
         else if( prefixExp[i] == '-')
            push(&operendStack,o1 - o2);
         else if( prefixExp[i] == '*')
            push(&operendStack,o1 * o2);
         else if( prefixExp[i] == '/')
            push(&operendStack,1 / o2);
         else{
            printf("Invalid Expression");
            return -1;
         }
      }
   }
   return operendStack.top;
}
// Driver code
int main()
{
	char exp[] = "*+69-31";

	// Function call
	printf("postfix evaluation: %d", evaluatePrefix(exp));
	return 0;
}

