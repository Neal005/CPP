#include<stdio.h>
#include "../lib/struct.h"
#include "../lib/function.h"

//Push Down
void pushDown(recordtype a[],int first, int last)
{
	int r=first;
	while(r<=(last-1)/2)
		if(last==2*r+1)
		{
			if(a[r].key>a[last].key) swap(&a[r],&a[last]);
			r=last;
		} else
			if((a[r].key>a[2*r+1].key)&&(a[2*r+1].key<=a[2*r+2].key))
			{
				swap(&a[r],&a[2*r+1]);
				r=2*r+1;
			} else
				if((a[r].key>a[2*r+2].key)&&(a[2*r+2].key<a[2*r+1].key))
				{
					swap(&a[r],&a[2*r+2]);
					r=2*r+2;
				} else r=last;
}

//Heap sort
void heapSort(recordtype a[],int n)
{
	int i;
	for(i=(n-2)/2;i>=0;i--)
		pushDown(a,i,n-1);
	for(i=n-1;i>=2;i--)
	{
		swap(&a[0],&a[i]);
		pushDown(a,0,i-1);
	}
	swap(&a[0],&a[1]);
}