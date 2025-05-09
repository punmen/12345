/*5-Design and implement C/C++ Program to obtain the Topological ordering of vertices in a given digraph.*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10][10],t[10],indeg[10],n,SUM=0;
	int u,k=0,v;
	int i,j,stack[10],top=-1;
	printf("\n\n\t topological ordering \n\n");
	printf("enter the directed acyclic graph\n\n");
	printf("enter the no of vertex\t");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
		indeg[i]=0;
	for(j=0;j<n;j++)
	{
		SUM=0;
		for(i=0;i<n;i++)
		{
			SUM+=a[i][j];
		}
		indeg[j]=SUM;
	}
	for(i=0;i<n;i++)
	{
		if(indeg[i]==0)
		{
			stack[++top]=i;
		}
	}
	while(top!=-1)
	{
		u=stack[top--];
		t[k++]=u;
		for(v=0;v<n;v++)
		{
			if(a[u][v]==1)
			{
				indeg[v]--;
				if(indeg[v]==0)
				{
					stack[++top]=v;
				}
			}
		}
	}
	printf("the topological sorting list\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",t[i]+1);
	}
}
