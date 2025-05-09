/*a. Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm.*/

#include<stdio.h>
#define INF 999
int a[10][10];
int min(int a,int b)
{
    return(a<b)?a:b;
}
void floyd(int n)
{
     int i,j,num;
     int k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);

    printf("\nShortest path matrix\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
void main()
{
    int n,i,j;
    printf("\nEnter the n value:");
    scanf("%d",&n);
    printf("\nEnter the graph data:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    floyd(n);


}
