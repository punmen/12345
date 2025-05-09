/*Design and implement C/C++ Program to sort a given set of n integer elements using Merge Sort
method and compute its time complexity. Run the program for varied values of n> 5000, and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
from a file or can be generated using the random number generator.*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define MAX 100000

void simple_merge(int a[],int low,int mid,int high)
{
int i=low;
int j=mid+1;
int k=low;
int c[MAX];
while(i<=mid &&j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
i++;
k++;
}
else
{
c[k]=a[j];
j++;
k++;
}

}
while(i<=mid)
c[k++]=a[i++];
while(j<=high)
{
c[k++]=a[j++];
}
for(i=low;i<=high;i++)
a[i]=c[i];
}





void merge_sort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
simple_merge(a,low,mid,high);
}
}
int main()
{
    int a[100000], i, n;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
       a[i]=rand()%100;

    }

        clock_t start = clock();
    merge_sort(a,0,n-1);
   clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;


       printf("Time taken to sort %d elements: %f seconds\n", n, timeTaken);

    return 0;
}
