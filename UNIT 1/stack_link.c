#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*top=NULL;

//struct node *top=NULL;

void push(int data)
{
	struct node* newnode;
	newnode=malloc(sizeof(newnode));
	
	if(newnode==NULL)
	{
		printf("stack overflow.");
		exit(1);
	}
	newnode->data=data;
	//newnode->link=NULL;
	
	newnode->link=top;
	top=newnode;
}

int isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int pop()
{
	struct node *temp;
	int val;
	if(isEmpty())
	{
		printf("stack underflow.");
		exit(1);
	}
	temp=top;
	val=temp->data;
	top=top->link;
	free(temp);
	temp=NULL;
	return val;
}

void print()
{
	struct node *temp;
	temp=top;
	printf("The stack elements are:");
	while(temp)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int main()
{
	int choice,data;
	while(1)
	{
		printf("1. PUSH \n");
		printf("2. POP \n");
		printf("3. PRINT \n");
		printf("4. QUIT \n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("Enter the element to be pushed:");
					scanf("%d",&data);
					push(data);
					break;
			case 2:
					data=pop();
					printf("Deleted element is %d\n",data);
					break;
					
			case 3:print();break;
			case 4:exit(1);
			default:
					printf("wrong choice\n");
					break;
		}
	}
	return 0;
}