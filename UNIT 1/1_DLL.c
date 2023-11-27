#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}NODE;

NODE* add_to_empty(NODE*,int);
NODE* insert_at_beg(NODE*,int);
NODE* insert_at_end(NODE*,int);
NODE* add_after_pos(NODE *,int,int);
NODE* create_list(NODE*);
NODE* del_first_m1(NODE*);
//NODE* del_first_m2(NODE*);
NODE* del_last(NODE*);
NODE* del_pos(NODE*,int);
void display(NODE*);

int main()
{
	NODE *head=NULL;
	
	printf("\n-------------------------------------------------------\n");
	head=add_to_empty(head,45);
	printf("Display after adding to empty list \n%d",head->data);
	
	printf("\n-------------------------------------------------------\n");
	printf("Inserting at the beginning\n");
	head=insert_at_beg(head,34);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("Inserting at the ending\n");
	head=insert_at_end(head,9);
	display(head);

	printf("\n-------------------------------------------------------\n");
	printf("Inserting IN Between\n");
	int pos=2;
	head=add_after_pos(head,25,pos);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("creating the list\n");
	head=create_list(head);
	display(head);
	
	printf("\n-------------------------------------------------------\n");
	printf("deleted the first node from the list method 1\n");
	head=del_first_m1(head);
	display(head);
	
	/*printf("\n-------------------------------------------------------\n");
	printf("deleted the first node from the list using method 2\n");
	head=del_first_m2(head);
	display(head);*/
	
	printf("\n-------------------------------------------------------\n");
	printf("deleted the last node from the list\n");
	head=del_last(head);
	display(head);
	
	int pos1=2;
	printf("\n-------------------------------------------------------\n");
	printf("deleted the intermediate node from the list\n");
	head=del_pos(head,pos1);
	display(head);
	return 0;
	
}

//function to insert a node in a empty list
NODE* add_to_empty(NODE* head,int data)
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}

//function to insert at the beginning

NODE* insert_at_beg(NODE* head,int data)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	temp->next=head;
	head->prev=temp;
	head=temp;
	
	return head;
}

void display(NODE* head)
{
	if(head!=NULL)
	{
		NODE *ptr=head;
		while(ptr != NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
}

NODE* insert_at_end(NODE* head,int data)
{
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	
	NODE *tp=head;
	while(tp->next!=NULL)
		tp=tp->next;
	tp->next=temp;
	temp->prev=tp;
	return head;
}

NODE* add_after_pos(NODE *head,int data,int pos)
{
	NODE* newp=NULL;
	NODE* temp=head;
	NODE* temp2=NULL;
	
	newp=add_to_empty(newp,data);
	while(pos!=1)
	{
		temp=temp->next;
		pos--;
	}
	if(temp->next==NULL)
	{
		temp->next=newp;
		newp->prev=temp;
	}
	else
	{
		temp2=temp->next;
		temp->next=newp;
		newp->prev=temp;
		temp2->prev=newp;
		newp->next=temp2;
	}
	return head;
}

NODE* create_list(NODE* head)
{
	int n,data,i;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	
	if(n==0)
		return head;
	/*
	printf("Enter the element for the node 1:");
	scanf("%d",&data);
	head=add_to_empty(head,data);
	
	for(i=1;i<=n;i++)
	{
		printf("Enter the element for the node %d:",i+1);
		scanf("%d",&data);
		head=insert_at_end(head,data);
	}
	*/
	
	//creating complete list at a time 
	for(i=1;i<=n;i++)
	{
		printf("Enter the element for the node %d:",i);
		scanf("%d",&data);
		head=insert_at_end(head,data);
	}
	return head;
}

// deleting the first node method 1
NODE* del_first_m1(NODE* head)
{
	head=head->next;
	free(head->prev);
	head->prev=NULL;
	return head;
}
/*
//deleting the first node method 2 traditional method as SLL
NODE* del_first_m2(NODE* head)
{
	NODE *temp=head;
	head=head->next;
	free(temp);
	temp=NULL;
	head->prev=NULL;
	return head;
}*/

NODE* del_last(NODE* head)
{
	NODE *temp=head;
	NODE *temp2;
	while(temp->next!=NULL)
		temp=temp->next;
	temp2=temp->prev;
	temp2->next=NULL;
	free(temp);
	temp=NULL;
	return head;
}

NODE* del_pos(NODE* head,int pos1)
{
	NODE *temp=head;
	NODE *temp2;
	while(pos1>1)
	{
		temp=temp->next;
		pos1--;
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	temp->next->prev=temp2;
	free(temp);
	temp=NULL;
	
	return head;
}
	
	
	