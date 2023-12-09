 #include<stdio.h>
 int visit[20];
 int p[20];
 void creategraph();
 void path(int, int);
 int findpath(int,int); 
 int a[100][100],n;
 int length;
 int main()
 {
   int i,v,s,d;
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("\nTo Find Path\n");
   printf("Enter the source and destination vertices..");
   scanf("%d %d",&s,&d);
   path(s,d);
  }

  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d %d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=1;
     }
  }


void path(int s, int d)
{
	int i,result;
	length=0;
	p[length]=s;
	for(i=1;i<=n;i++)
		visit[i]=0;
	result=findpath(s,d);
	if(result)
	{
		printf("The vertices in the path are..\n");
		for(i=0;i<=length;i++)
			printf("%d ",p[i]);
	}
	else
		printf("Path not found..\n");
}
	
int findpath(int s, int d)
{
	int i;
	visit[s]=1;
	for(i=1;i<=n;i++)
	{
		if ((a[s][i]==1)&&(visit[i]==0))
		{
            ++length;
            p[length]=i;
            if((i==d) || findpath(i,d)) 
               return 1;				
		}
	}
	length--;
	return 0;
}
	       
	










 /*void path (int s, int d)
 {
	 int i,j,t;
	 length=0;
	 for(i=1;i<=n;i++)
		 visit[i]=0;
	 p[length]=s;
	 t=findpath(s,d);
	 if(t)
	 {
	      printf("Path found..\n");
	      printf("The length= %d\n",length);
	      printf("the vertices in the path..\n");
	      for(i=0;i<=length;i++)
	          printf("%d ",p[i]);
	 }
 }
		 
int findpath(int s, int d)
	{
         int u;
	     visit[s]=1;
		
	     for(u=1;u<=n;u++)
	        {
	         if((a[s][u]==1)&&(visit[u]==0))
	               {
		            ++length;
		            p[length]=u;
		           if((u==d) || findpath(u,d))
		              return 1;
                   }
	        }
	           --length;
	          return 0;
	    }
 			
		
int findpath(int s, int d)
{
	int u;
	visit[s]=1;
	for(u=1;u<=n;u++)
    {
		if((a[s][u]==1)&&(visit[u]==0))
		{
			length++;
			p[length]=u;
			if((u==d) || findpath(u,d))
				return 1;
		}
	}
	length--;
	return 0;
}
	*/
