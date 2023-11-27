#include<stdio.h>

#define MAX 10

void readgraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);
int stronglyconnected(int a[MAX][MAX],int n);
void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n);
int weakconnected(int b[MAX][MAX],int n);

int main()
{
	int a[MAX][MAX],n;
	
	printf("Enter the NO. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the values to adj matrix\n");
	readgraph(a,n);
	
	if(stronglyconnected(a,n))
		printf("Graph ia strongly connected\n");
		
	else
	{
		int b[MAX][MAX]={0};
		removeEdgeDirection(a,b,n);
		if(weakconnected(b,n))
			printf("Graph is weakly connected\n");
		else
		
			printf("Graph is disconnected\n");
		
	}
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
}

int weakconnected(int b[MAX][MAX],int n)
{
	int visited[MAX]={0};
	bfs(b,n,visited,0);
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
			return 0;
	}
	return 1;
}


int stronglyconnected(int a[MAX][MAX],int n)
{
	int visited[MAX]={0};
	for(int v=1;v<=n;v++)
	{
		for(int j=1;j<=n;j++)
			visited[j]=0;
		bfs(a,n,visited,v);
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				return 0;
			}
		}
	}
	return 1;
}

void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1)
				b[i][j]=b[j][i]=1;
		}
	}
}

void bfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int q[n]; //QUeue
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	printf("%d\t",source);
	
	int v;
	while(f<=r)
	{
		v=q[f++];
		
		for(int i=1;i<=n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
				printf("%d\t",i);
			}
		}printf("\n");
	}
}
