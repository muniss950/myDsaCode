// BFS for a digraph using Linked list
#include<stdio.h>
#include<stdlib.h>


int f,r,n;
int visit[100];
int q[100];


struct node
{
	int data;
	struct node *next;
};


struct node *a[100];

int qempty();
void qinsert(int v);
void bfs(int v);
void creategraph();
int qdelete();
void insert(int i, int j);

int main()
{
	int v;
	f=r=-1;
	printf("Enter the no of verticies...\n");
	scanf("%d",&n);
	creategraph();

	printf("Enter the src vertex...\n");
	scanf("%d",&v);

	printf("Verticies reachable from source vertex using bfs traversal are...\n");
	bfs(v);
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
void bfs(int v)
{
	struct node *p;
	int w;
	visit[v]=1;
	printf("%d ",v);
	qinsert(v);
	while(!qempty())
	{
		v=qdelete();
		for(p=a[v];p!=NULL;p=p->next)
		{
			w=p->data;
			if(visit[w]==0)
			{
				visit[w]=1;
				printf("%d ",w);
				qinsert(w);
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



