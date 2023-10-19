#include<stdio.h>
#include "../lib/struct.h"
#include "../lib/function.h"

//Find pivot
int variantFindPivot(recordtype a[], int i,int j)
{
	keytype firstkey;
	int k ;
	k=i+1;
	firstkey=a[i].key;
	while (k<=j&&a[k].key==firstkey) k++;
	if(k>j) return -1;
	else
		if(a[k].key<firstkey) return i;
		else return k;
}

//Partition
int variantPartition(recordtype a[],int i,int j,keytype pivot)
{
	int L,R;
	L=i;
	R=j;
	while(L<=R)
	{
		while(a[L].key>=pivot) L++;
		while(a[R].key<pivot) R--;
		if(L<R) swap(&a[L],&a[R]);
	}
	return L;
}

//Variant quick sort
void variantQuickSort(recordtype a[],int i,int j)
{
	keytype pivot;
	int pivotIndex,k;
	pivotIndex=variantFindPivot(a,i,j);
	if(pivotIndex!=-1)
	{
		pivot=a[pivotIndex].key;
		k=variantPartition(a,i,j,pivot);
		variantQuickSort(a,i,k-1);
		variantQuickSort(a,k,j);
	}
}