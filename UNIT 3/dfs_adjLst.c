//Adjacency List representation of graph
//DFS traversal
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void createList(NODE *A[MAX]);
void addEdge(NODE *A[MAX],int src,int dest);
void dfs(NODE *A[MAX],int visited[MAX],int src);
int main()
{
	int src;
	NODE *A[MAX]={NULL};
	int visited[MAX]={0};
	
	printf("Enter the graph data\n");
	createList(A);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("DFS Traversal\n");
	dfs(A,visited,src);
}
void createList(NODE *A[MAX])
{
	int src,dest,choice;
	do
	{
		printf("Enter the source and dest\n");
		scanf("%d%d",&src,&dest);
		
		addEdge(A,src,dest);
		addEdge(A,dest,src); //Undirected graph
		
		printf("Do you want to add one more edge\n");
		scanf("%d",&choice);
	}while(choice);
}
void addEdge(NODE *A[MAX],int src,int dest)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=dest;
	
	newNode->next=A[src];
	A[src]=newNode;
}
void dfs(NODE *A[MAX],int visited[MAX],int src)
{
	visited[src]=1;
	printf("%d",src);
	
	NODE *p=A[src];
	while(p!=NULL)
	{
		if(visited[p->info]==0)
			dfs(V,visited,p->info);
		p=p->next;
	}
}