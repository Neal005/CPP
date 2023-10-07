#include <iostream>
#include <stdio.h>
#include "./lib/struct.h"
#include "./lib/sort.h"
#define mod 1

int main()
{
	int n;
	printf("Enter a number of elements: ");
	scanf("%d",&n);
	recordtype a[n];
	printf("*Enter an array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i].key);
	if(mod==1) SelectionSort(a,n);
	if(mod==2) InsertionSort(a,n);
	if(mod==3) BubbleSort(a,n);
	if(mod==4) QuickSort(a,0,n);
	if(mod==5) HeapSort(a,n);
	printf("*Sort type \"%d\": \n",mod);
	for(int i=0;i<n;i++)
		printf("%d ",a[i].key);
	return 0;
}