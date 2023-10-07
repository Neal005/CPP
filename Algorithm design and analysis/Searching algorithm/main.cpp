#include<iostream>
#include<stdio.h>
#include "./lib/search.h"
#define mod 1
#define oo 999999

int main()
{
	int n,find=oo,res;
	printf("Enter a number of array: ");
	scanf("%d",&n);
	int A[n];
	printf("Enter array index:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("Find what: "); scanf("%d",&find);
	if(mod==1) res=SequenceSearch(find,A,n);
	if(mod==2) res=BinarySearch(find,A,0,n-1);
	printf("*Searching type %d:\n\tThe result in cell: %d",mod,res+1);
	if(res+1==1) printf("st");
	if(res+1==2) printf("rd");
	if(res+1>2) printf("th");
	return 0;
}