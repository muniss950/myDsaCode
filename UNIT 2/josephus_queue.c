#include<stdio.h>
#include<stdlib.h>

struct node
{
	int player_id;
	struct node *next;
};

int main()
{
	int n,k,i,count;
	printf("enter the number of players:");
	scanf("%d",&n);
	printf("\n Enter the value of k(every kth player gets eliminated:");
	scanf("%d",&k);
	
	//create circular linked list containing all the players
	struct node *start=malloc(sizeof(struct node));
	start->player_id=1;
	struct node *ptr=start;
	
	for(i=2;i<=n;i++)
	{
		struct node *new_node=malloc(sizeof(struct node));
		ptr->next=new_node;
		new_node->player_id=i;
		new_node->next=start;
		ptr=new_node;
	}
	
	for(count=n;count>1;count--)
	{
		for(i=0;i<k-1;++i)
		{
			ptr=ptr->next;
			printf("%d deleted ",ptr->next->player_id);
		}
		struct node *temp=ptr->next;
		ptr->next=ptr->next->next;
		free(temp);
		temp=NULL;
	}
	printf("The winner is player %d",ptr->player_id);
	return 0;
}