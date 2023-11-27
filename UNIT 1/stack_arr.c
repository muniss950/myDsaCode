#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top=-1;

void push(int data)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		return;
	}
	else
	{
		top=top+1;
		stack_arr[top]=data;
	}
}

int pop()
{
	int value;
	if(top == -1)
	{
		printf("stack underflow\n");
		exit(1);
	}
	value=stack_arr[top];
	top=top-1;
	return value;
}

void print()
{
	int i;
	if(top == -1)
	{
		printf("stack underflow\n");
		exit(1);
	}
	for(i=top;i>=0;i--)
		printf("%d\t",stack_arr[i]);
	printf("\n");
}

int main()
{
	int data;
	push(1);
	push(2);
	push(3);
	data=pop();
	printf("%d\n",data);
	print();
	return 0;
}

	
	