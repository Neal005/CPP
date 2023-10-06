#include<stdio.h>

int Sequence_search(int x,int a[ ],int n)
{
	int found,i;
	found=0;
	i=0;
	while (i<n&&!found)
	if (a[i]==x)
	found=1;
	else
	i=i+1;
	if(i==n) return -1;
	return i;
}