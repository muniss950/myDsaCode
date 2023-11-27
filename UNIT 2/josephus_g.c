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
	printf("Enter the number of players\n");
	scanf("%d",&n);
	
	printf("Enter the kth player to be eliminated\n");
	scanf("%d",&k);
	
	struct node *start=malloc(sizeof(struct node));
	start->player_id=1;
	
	struct node *ptr=start;
	
	for(i=2;i<=n;i++)
	{
		struct node *new=malloc(sizeof(struct node));
		new->player_id=i;
		ptr->next=new;
		new->next=start;
		ptr=new;
	}
	
	for(count=n;count>1;count--)
	{
		for(i=1;i<=k-1;i++)
			ptr=ptr->next;
			
		printf("player getting deleted is %d\n",ptr->next->player_id);
		struct node *temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
		temp=NULL;
	}
	printf("Winner is %d\t:",ptr->player_id);
	return 0;
}

		