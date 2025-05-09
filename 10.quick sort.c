/*Design and implement C/C++ Program to sort a given set of n integer elements using Quick Sort
method and compute its time complexity. Run the program for varied values of n> 5000 and
record the time taken to sort. Plot a graph of the time taken versus n*/
#include<stdio.h>
#include<time.h>
int partition(int low,int high,int a[])
{
   int i,j,key,temp;
   i=0,j=high+1;
   key=a[low];
   while(i<=j)
   {
      do i++;while(key>=a[i]);
      do j--;while(key<a[j]);
      if(i<j)
      {
	 temp=a[i];
	 a[i]=a[j];
	 a[j]=temp;
      }
   }
      temp=a[low];
      a[low]=a[j];
      a[j]=temp;
      return j;
}
void quick_sort(int low,int high,int a[])
{
    int mid;
    if(low<high)
    {
       mid=partition(low,high,a);
       quick_sort(low,mid-1,a);
       quick_sort(mid+1,high,a);
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
    quick_sort(0,n,a);
   clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;


       printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

    return 0;
}


