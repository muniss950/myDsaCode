//BFS Traversal for a connected graph
//Adjacency List implementation
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void createList(NODE *V[MAX]);
void addEdge(NODE *V[MAX],int src,int dest);
void bfs(NODE *V[MAX],int visited[MAX],int src);
//void destroyGraph(NODE *V[MAX],int n);

int main()
{
	int visited[MAX]={0};
	int src;
	NODE *V[MAX]={NULL}; //adj List initialized to be empty

	createList(V);
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	printf("BFS Traversal\n");
	bfs(V,visited,src);
}

void bfs(NODE *V[MAX],int visited[MAX],int src)
{
	int q[MAX];	//Queue
	int front=0,rear=-1;	//Queue init
	int v;
	
	q[++rear]=src;		//Enq src
	visited[src]=1;
		
	while(front<=rear)		//q not empty
	{
		v=q[front++];		//Deq src
		printf("%d ",v);
		
		NODE *p=V[v];
		while(p!=NULL)			
		{
			if(visited[p->info]==0)
			{
				q[++rear]=p->info;
				visited[p->info]=1;
			}
			p=p->next;
		}
	}
}
void createList(NODE *V[MAX])
{
	int src,dest,choice;
	do
	{
		printf("Enter the source and dest\n");
		scanf("%d%d",&src,&dest);
		
		addEdge(V,src,dest);
		addEdge(V,dest,src); //Undirected graph
		
		printf("Do you want to add one more edge\n");
		scanf("%d",&choice);
	}while(choice);
}
void addEdge(NODE *V[MAX],int src,int dest)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=dest;
	
	newNode->next=V[src];
	V[src]=newNode;
}