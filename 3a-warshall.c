/*b. Design and implement C/C++ Program to find the transitive closure using Warshal's algorithm.*/
#include<stdio.h>
#include<stdlib.h>
int a[10][10];
void warshall(int n)
{
 int i,j,num;
 int k;
 for(k=1;k<=n;k++)
 {
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
  }
 }
 printf("\nthe transitive closure matrix is:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d",a[i][j]);
  }
  printf("\n");
 }
}
void main()
{
 int i,j,n;
 printf("enter the no of vertices\n");
 scanf("%d",&n);
 printf("enter the adjacency matrix\n");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 {
  scanf("%d",&a[i][j]);
 }
 warshall(n);

}

