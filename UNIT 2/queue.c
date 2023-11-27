#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int);
int dequeue();
int peek();
void print();
int isfull();
int isempty();

int main()
{
	int choice,data;
	while(1)
	{
		printf("\n1.INsert\n");
		printf("2.Delete\n");
		printf("3.Print first Element\n");
		printf("4.Print all the elements\n");
		printf("5.Quit\n");
		
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("Enter the element to be added in the queue:");
					scanf("%d",&data);
					enqueue(data);
					printf("Element is added in the queue successfully.\n");
					break;
			case 2:
					data=dequeue();
					printf("Deleted element is:%d",data);
					break;
			case 3:
					printf("The first Element of the queue is %d",peek());
					break;
			
			case 4:
					print();
					break;
			
			case 5:exit(1);
			default:
					printf("wrong choice\n");
		}
		//return 0;
	}
	return 0;
}

void enqueue(int data)
{
	if(isfull())
	{
		printf("queue overflow\n");
		exit(1);
	}
	if(front==-1)
		front=0;
	rear++;
	queue[rear]=data;
}

int dequeue()
{
	int data;
	if(isempty())
	{
		printf("queue underflow\n");
		exit(1);
	}
	data=queue[front];
	front++;
	return data;
}

int isempty()
{
	if(front==-1|| front==rear+1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}

int peek()
{
	if(isempty())
	{
		printf("Queue underflow,\n");
		exit(1);
	}
	return queue[front];
}
	
void print()
{
	int i;
	if(isempty())
	{
		printf("queue underflow\n");
		exit(1);
	}
	printf("Queue:\n");
	for(i=front;i<=rear;i++)
		printf("%d\t",queue[i]);
	printf("\n");
}
			
		
		