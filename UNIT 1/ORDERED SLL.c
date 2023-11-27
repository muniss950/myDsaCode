#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void display(struct node*);
struct node* insert(struct node *head,int data);

int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=45;
	head->link=malloc(sizeof(struct node));
	head->link->data=98;
	head->link->link=malloc(sizeof(struct node));	
	head->link->link->data=120;
	head->link->link->link=NULL;
	
	printf("\n---------------------------------------\n");
	display(head);
	
	printf("\n---------------------------------------\n");
	printf("\n INsert List\n");
	head=insert(head,66);
	display(head);	
	
	return 0;
}
	
void display(struct node* head)
{
	if(head!=NULL)
	{
		printf("\nIts me display\n");
		struct node *ptr=head;
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->link;
		}
	}
}



struct node* insert(struct node *head,int data)
{
	struct node *temp;
	struct node *newP=malloc(sizeof(struct node));
	newP->data=data;
	newP->link=NULL;
	
	int key=data;
	if(head==NULL || key<head->data)
	{
		newP->link=head;
		head=newP;
	}
	else
	{
		temp=head;
		while(temp->link!=NULL && temp->link->data<key)
			temp=temp->link;
		newP->link=temp->link;
		temp->link=newP;
	}
	return head;
}

