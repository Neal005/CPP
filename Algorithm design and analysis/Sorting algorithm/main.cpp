#include <iostream>
#include <stdio.h>
#include "./lib/struct.h"
#include "./lib/insertionSort.h"

int main()
{
	int n;
	printf("Enter a number of elements: "); scanf("%d",&n);
	recordtype a[n];
	printf("Enter an array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].key);
	InsertionSort(a,n);
	printf("*Selection sort:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i].key);
	return 0;
}