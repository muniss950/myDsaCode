#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void display(struct node*);
void free_list(struct node*);
void count_of_nodes(struct node*);
void add_at_end(struct node*,int);
struct node* insert_at_beginning(struct node*,int);
void insert_at_the_position(struct node *,int,int);
struct node* del_first(struct node *);
struct node* del_last(struct node *);
void del_last_SP(struct node *);
void del_pos(struct node *,int);
struct node* del_list(struct node*);

int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=45;
	head->link=malloc(sizeof(struct node));
	head->link->data=98;
	head->link->link=malloc(sizeof(struct node));	
	head->link->link->data=3;
	head->link->link->link=NULL;
	
	printf("\n---------------------------------------\n");
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nInsert node at the End\n");
	add_at_end(head,67);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nInsert node at the Beginning\n");
	head=insert_at_beginning(head,40);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nInsert node at the position\n");
	insert_at_the_position(head,52,3);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nDelete node at the Beginning \n");
	head=del_first(head);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nDelete node at the End\n");
	head=del_last(head);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nDelete node at the End using SP\n");
	del_last_SP(head);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nDelete node at the intermediate position\n");
	int pos=2;
	del_pos(head,pos);
	display(head);
	count_of_nodes(head);
	
	printf("\n---------------------------------------\n");
	printf("\nDelete Entire List\n");
	head=del_list(head);
	display(head);
	count_of_nodes(head);
	
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

void free_list(struct node* p)
{
	struct node* d = p;
	printf("\nIts me free_list\n");
	while(p!= NULL)
	{
		p = p->link;
		printf("\ndeleting the node with info %d\n",d->data);
		free(d);
		d = p;	
	}
}

void count_of_nodes(struct node* head)
{
	int count=0;
	if(head==NULL)
		printf("\nLinked list is empty to count");
	struct node *ptr=NULL;
	ptr=head;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	printf("\nNumber of nodes in a SLL is %d",count);
}

void add_at_end(struct node *head,int data)
{
	struct node *ptr,*temp;
	ptr=head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;

	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
}

struct node* insert_at_beginning(struct node* head,int d)
{
	struct node *ptr=malloc(sizeof(struct node));
	ptr->data=d;
	ptr->link=NULL;
	
	ptr->link=head;
	head=ptr;
	return head;
}

void insert_at_the_position(struct node *head,int data,int pos)
{
	struct node *ptr=head;
	struct node *temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	
	pos--;
	while(pos!=1)
	{
		ptr=ptr->link;
		pos--;
	}
	temp->link=ptr->link;
	ptr->link=temp;
}

struct node* del_first(struct node *head)
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		struct node *temp=head;
		head=head->link;
		printf("\nThe element getting deleted is %d:\t",temp->data);
		free(temp);
		temp=NULL;
	}
	return head;
}

struct node* del_last(struct node *head)
{
	if(head==NULL)
		printf("\nList is empty:del_last");
	else if(head->link==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		struct node *temp=head;
		struct node *temp2=head;
		while(temp->link!=NULL)
		{
			temp2=temp;
			temp=temp->link;
		}
		printf("Its me del_last\n");
		printf("\nThe node getting deleted is %d:\t",temp->data);
		temp2->link=NULL;
		free(temp);
		temp=NULL;
	}
	return head;
}

void del_last_SP(struct node *head)
{
	if(head==NULL)
		printf("\nList is empty");
	else if(head->link==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		struct node *temp=head;
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		printf("\nThe node getting deleted is %d:\t",temp->link->data);
		
		free(temp->link);
		temp->link=NULL;
	}
}	

void del_pos(struct node *head,int pos)
{
	struct node *current=head;
	struct node *previous=head;
	if(head==NULL)
		printf("list is already empty");
	else if(pos==1)
	{
		head=current->link;
		free(current);
		current=NULL;
	}
	else
	{
		while(pos!=1)
		{
			previous=current;
			current=current->link;
			pos--;
		}
		printf("\nThe node which is deleted is :%d\n",current->data);
		previous->link=current->link;
		free(current);
		current=NULL;
	}
}
		
struct node* del_list(struct node* head)
{
	if(head==NULL)
		printf("NO nodes delete List\n");
	struct node *temp=head;
	while(temp!=NULL)
	{
		temp=temp->link;
		printf("\ndeleted is :%d",head->data);
		free(head);
		head=temp;
	}
	return head;
}


