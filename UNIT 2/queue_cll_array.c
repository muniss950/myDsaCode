#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int cqueue[MAX];
int front=-1;
int rear = -1;

void enqueue(int);
int dequeue();
int peek();
int isempty();
int isfull();
void print();

int main()
{
	int choice,data;
	while(1)
	{
		printf("\n1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print first element\n");
		printf("4. Print all the elements\n");
		printf("5. Quit\n");
		
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter the element to be added into the queue\n");
					scanf("%d",&data);
					enqueue(data);
					break;
					
			case 2:	data=dequeue();
					printf("Ignored element is %d",data);
					break;
					
			case 3:	printf("The element int eh queue is %d\n",peek());
					break;
					
			case 4:	print();
					break;
					
			case 5:	exit(1);
			
			default:	printf("Wrong choice\n");
		}
	}
	return 0;
}

void enqueue(int data)
{
	if(isfull())
	{
		printf("queue overflow.\n");
		exit(1);
	}
	if(front == -1)
		front =0;
	
	if(rear== MAX-1)
		rear=0;
	else
		rear=rear+1;
	cqueue[rear]=data;
}

int dequeue()
{
	int data;
	if(isempty())
	{
		printf("Queue underflow.\n");
		exit(1);
	}
	data=cqueue[front];
	
	if(front==rear)
		front=rear=-1;
	else if(front==MAX-1)
		front=0;
	else
		front=front+1;
	return data;
}

int isempty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
		return 0;
}

int peek()
{
	if(isempty())
	{
		printf("Queue underflow\n");
		exit(1);
	}
	return cqueue[front];
}

void print()
{
	int temp;
	if(isempty())
	{
		printf("queue underflow\n");
		exit(1);
	}
	temp=front;
	if(front<=rear)
	{
		while(temp<=rear)
		{
			printf("%d\n",cqueue[temp]);
			temp++;
		}
	}
	else
	{
		while(temp<=MAX-1)
		{
			printf("%d\n",cqueue[temp]);
			temp++;
		}
		temp=0;
		while(temp<=rear)
		{
			printf("%d\n",cqueue[temp]);
			temp++;
		}
	}
	printf("\n");
}
	