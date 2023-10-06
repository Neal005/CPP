#include<stdio.h>
#include "../lib/struct.h"
#include "../lib/function.h"

void SelectionSort(recordtype a[], int n)
{
	int i,j,lowindex;
	keytype lowkey;
	for(i=0;i<=n-2;i++)
	{
		lowkey=a[i].key;
		lowindex=i;
		for(j=i+1;j<=n-1;j++)
		if(a[j].key<lowkey)
		{
			lowkey=a[j].key;
			lowindex=j;
		}
		Swap(&a[i],&a[lowindex]);
	}
}