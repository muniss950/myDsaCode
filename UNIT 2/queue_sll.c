#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
} *front=NULL,*rear=NULL;

void enqueue(int);
int dequeue();
int peek();
void print();
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
 
void enqueue(int n)
{
	struct node *temp=malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("No space.\n");
		exit(1);
	}
	temp->data=n;
	temp->link=NULL;
	if(rear==NULL)
		front=rear=temp;
	else
	{
		rear->link=temp;
		rear=temp;
	}
}

int dequeue()
{
	int data;
	struct node *temp=front;
	if(isempty())
	{
		printf("Queue underflow.\n");
		exit(1);
	}
	data=temp->data;
	front=front->link;
	free(temp); 
	temp=NULL;
	return data;
}

int isempty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}
 
void print()
{
	struct node *temp;
	temp=front;
	if(isempty())
	{
		printf("Queue underflow.\n");
		exit(1);
	}
	printf("Queue:\n");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int peek()
{
	if(isempty())
	{
		printf("Queue underflow\n");
		exit(1);
	}
	return front->data;
}
