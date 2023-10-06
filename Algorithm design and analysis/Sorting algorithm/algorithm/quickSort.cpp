#include<stdio.h>
#include "../lib/struct.h"
#include "../lib/function.h"

//Find Pivot
int FindPivot(recordtype a[ ], int i,int j)
{
	keytype firstkey;
	int k ;
	k=i+1;
	firstkey=a[i].key;
	while ( k<=j&&a[k].key==firstkey) k++;
	if (k>j) return -1;
	else
		if (a[k].key>firstkey) return k; else return i;
}

//Partition
int Partition(recordtype a[],int i,int j,keytype pivot)
{
	int L,R;
	L=i;
	R=j;
	while(L<=R)
	{
		while(a[L].key<pivot) L++;
		while(a[R].key>=pivot) R--;
		if(L<R) Swap(&a[L],&a[R]);
	}
	return L;
}

//Quick Sort
void QuickSort(recordtype a[],int i,int j)
{
	keytype pivot;
	int pivotindex,k;
	pivotindex=FindPivot(a,i,j);
	if (pivotindex!=-1)
	{
		pivot=a[pivotindex].key;
		k=Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}