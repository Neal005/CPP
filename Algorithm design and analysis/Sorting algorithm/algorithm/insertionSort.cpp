#include<stdio.h>
#include "../lib/struct.h"
#include "../lib/function.h"

void InsertionSort(recordtype a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		j=i;
		while (j>0&&a[j].key<a[j-1].key)
		{
			Swap(&a[j],&a[j-1]);
			j--;
		}
	}
}