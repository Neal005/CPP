#include<stdio.h>
#include "../lib/struct.h"

void readData(recordtype a[],int *n)
{
	if(debug) printf("Reading data\n");
	int i=0;
	FILE *f;
	if(debug)printf("Opening file\n");
	f=fopen("data.txt","r");
	if(f==NULL) printf("Can be open file\n");
	else
	while(!feof(f))
	{
		fscanf(f,"%d %f",&a[i].key,&a[i].otherfields);
		i++;
	}
	fclose(f);
	*n=i;
}

void printData(recordtype a[],int n)
{
	if(debug)printf("Print data\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}

void swap(recordtype *x, recordtype *y)
{
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}