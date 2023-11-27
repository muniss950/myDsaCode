// DFS for a digraph using Linked list
#include<stdio.h>
#include<stdlib.h>



int visit[100];



struct node
{
	int data;
	struct node *next;
};


struct node *a[100];



void dfs(int v);
void creategraph();
void insert(int i, int j);

int main()
{
	int v;

	printf("Enter the no of verticies...\n");
	scanf("%d",&n);
	creategraph();

	printf("Enter the src vertex...\n");
	scanf("%d",&v);

	printf("Verticies reachable from source vertex using bfs traversal are...\n");
	dfs(v);
	return 0;

}

void creategraph()
{
	int i,j;
	for(i=1;i<=n;i++)
		a[i]=NULL;

	while(1)
	{
		printf("Enter the src & dst\n");
		scanf("%d%d",&i,&j);
		if(i==0 && j==0)
			break;
		insert(i,j);
	}
}
void insert(int i,int j)
{

	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=j;
	temp->next=a[i];
	a[i]=temp;
}
void dfs(int v)
{
	struct node *p;
	int w;
	visit[v]=1;
	printf("%d ",v);
		for(p=a[v];p!=NULL;p=p->next)
		{
			w=p->data;
			if(visit[w]==0)
			{
				dfs(w);
			}
		}
	}
}

void qinsert(int v)
{
	r++;
	q[r]=v;
	if(f==-1)
		f=0;
}
int qempty()
{
	if(f==-1)
	return 1;
	return 0;
}
int qdelete()
{
	int w;
	w=q[f];
	if(f==r)
	f=r=-1;
	else
	f++;
	return w;
}



