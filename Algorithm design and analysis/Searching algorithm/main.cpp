#include<iostream>
#include<stdio.h>
#include "./lib/search.h"

int main()
{
	int A[11]={1,4,5,3,2,7};
	int i=Sequence_search(30,A,6);
	printf("\n%d",i);
	return 0;
}