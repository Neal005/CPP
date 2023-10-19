#include<stdio.h>
#include "../lib/struct.h"
#include "../lib/function.h"

void bubbleSort(recordtype a[],int n)
{
	if(debug)printf("Bubble sort\n");
	int i,j;
	for(i=0;i<=n-2;i++)
		for(j=n-1;j>=i+1;j--)
			if(a[j].key<a[j-1].key)
				swap(&a[j],&a[j-1]);
}