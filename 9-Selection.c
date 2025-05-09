/*Design and implement C/C++ Program to sort a given set of n integer elements using Selection
Sort method and compute its time complexity. Run the program for varied values of n> 5000 and
record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
from a file or can be generated using the random number generator.*/
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void sort(int a[],int n)
{
 int min,i,j,temp;
 for(i=0;i<n-2;i++)
 {
  min=i;
  for(j=i+1;j<n-1;j++)
  {
   if(a[j]<a[min])
   {
    min=j;
    //count++;
   }
  }
  temp=a[i];
  a[i]=a[min];
  a[min]=temp;
 }
}

int main()
{
    int a[10000], i, n;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
       a[i]=rand()%100;

    }

        clock_t start = clock();
    sort(a, n);
   clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;


       printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

    return 0;
}
