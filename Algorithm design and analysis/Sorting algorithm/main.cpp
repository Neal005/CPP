#include <iostream>
#include <stdio.h>
#include "./lib/struct.h"
#include "./lib/sort.h"

int main()
{
	int n,choose;
	printf("Enter a number of elements: "); scanf("%d",&n);
	recordtype a[n];
	printf("*Enter an array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].key);
//	SelectionSort(a,n);
//	InsertionSort(a,n);
//	BubbleSort(a,n);
//	QuickSort(a,0,n);
	HeapSort(a,n);
	printf("*Sort: \n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i].key);
	return 0;
}