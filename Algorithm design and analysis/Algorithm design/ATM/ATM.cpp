#include<stdio.h>
#include<iostream>
#define debug 1

//struct
typedef int keytype;
typedef char* othertype;

typedef struct
{
	keytype value;
	othertype description;
}recordtype;

//function
void readData(recordtype money[],int *kind)
{
	if(debug) printf("Reading data\n");
	int i=0;
	FILE *f;
	if(debug)printf("Opening file\n");
	f=fopen("ATM.txt","r");
	if(f==NULL) printf("Can be open file\n");
	else
	{
		char temp;
		int j;
		while(!feof(f))
		{
			if(debug) printf("Loop %d\n",i+1);
			fscanf(f,"%d",&money[i].value);
			if(debug) printf("%d ",money[i].value);
			fscanf(f,"%c",&temp);
			fgets(money[i].description,50,f);
			money[i].description[strlen(money[i].description)-1]='\0';
			if(debug) printf("%s",money[i].description);
			if(debug) printf("\n");
			i++;
		}
	}	
	fclose(f);
	*kind=i;
	if(debug) printf("%d",*kind);
}

void printData(recordtype a[],int n)
{
	if(debug)printf("Print data\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%s\n",i+1,a[i].value,a[i].description);
	}
}

void swap(recordtype *x,recordtype *y)
{
	recordtype temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int variantFindPivot(recordtype a[], int i,int j)
{
	keytype firstkey;
	int k ;
	k=i+1;
	firstkey=a[i].value;
	while (k<=j&&a[k].value==firstkey) k++;
	if(k>j) return -1;
	else
		if(a[k].value<firstkey) return i;
		else return k;
}

int variantPartition(recordtype a[],int i,int j,keytype pivot)
{
	int L,R;
	L=i;
	R=j;
	while(L<=R)
	{
		while(a[L].value>=pivot) L++;
		while(a[R].value<pivot) R--;
		if(L<R) swap(&a[L],&a[R]);
	}
	return L;
}

void variantQuickSort(recordtype a[],int i,int j)
{
	keytype pivot;
	int pivotIndex,k;
	pivotIndex=variantFindPivot(a,i,j);
	if(pivotIndex!=-1)
	{
		pivot=a[pivotIndex].value;
		k=variantPartition(a,i,j,pivot);
		variantQuickSort(a,i,k-1);
		variantQuickSort(a,k,j);
	}
}

//algorithm
void atmGreedy(recordtype a[],int kind,int n)
{
	int sum=0,stop=0;
	for(int i=0;i<kind;i++)
	{
		stop=0;
		do
		{
			if(sum+a[i].value<=n)
			{
				sum+=a[i].value;
//				sol[i]++;
			}
			else stop=1;
		}while(stop==0);
	}
}

//main
int main()
{
	int n,kind;
	recordtype money[100];
	readData(money,&kind);
	//printData(a,kind);
	
	return 0;
}