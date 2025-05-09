/*2.Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Prim's algorithm.*/
#include<stdio.h>
#include<stdlib.h>
int u,v,n,i,j,ne=1,k,a,b;
int parent[10],min,mincost=0,cost[10][10];
int find(int);
int union1(int,int);
void main()
{
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
	}
	printf("MST\n");
	while(ne<n) {
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
        {
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		u=fipar(u);
		v=fipar(v);
		if(union1(u,v))
        {
			printf("\n %d:edge(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;

		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Minimun cost=%d",mincost);
}
int fipar(int i)
{
    while(parent[i])
        i=parent[i];
        return i;
}
int union1(int i,int j)
{
   if(i!=j)
{
    parent[j]=i;
    return 1;
}
return 0;
}
