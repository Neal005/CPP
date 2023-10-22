#include<stdio.h>
#include<iostream>
#define debug 2

//struct
typedef float keytype;

typedef struct
{
	int h,t,d=0;
	keytype w;
} edge;

//functions
void addEdge(edge e[],int p,int h,int t,int w)
{
	e[p].h=h;
	e[p].t=t;
	e[p].w=w;
}

void initEdge(edge e[])
{
	for(int i=0;i<100;i++)
	{
		e[i].h=e[i].t=e[i].w=-1;
	}
}

void resetArray(int checked[],int dd[],int n)
{
	for(int i=0;i<n;i++)
		checked[i]=dd[i]=0;
}

void deleteReEdge(edge e[],int n,int i)
{
	if(debug==2) printf("Delete reEdge\n");
	int j=i;
	int stop=0;
	do
	{
		if(e[i].h==e[j].t&&e[i].t==e[j].h&&e[j].h!=e[j].t)
		{
			if(debug==2) printf("head: %d - tail: %d\n",e[j].h,e[i].t); 
			e[j].d=1;
			stop=1;
		}
		j++;
	} while(!stop&&j<n*n-2);
}

void swap(edge *x,edge *y)
{
	edge temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void readData(edge e[],int *n)
{
	if(debug==1) printf("Read data\n");
	int count=0,n1;
	float temp;
	FILE *f;
	f=fopen("TSP.txt","r");
	if(f==NULL) printf("cant be open!\n");
	else
	{
		if(debug==1) printf("Opening data\n");
		fscanf(f,"%d",n);
		count=0;
		if(debug==1) printf("%d\n",n);
		for(int i=0;i<*n;i++)
			for(int j=0;j<*n;j++)
			{
				if(debug==1) printf("Scan domain\n");
				fscanf(f,"%f",&temp);
				if(debug==1) printf("%d ",temp);
				if(i!=j)
				{
					addEdge(e,count,i,j,temp);
					count++;
				}
			}
	}
}

void printData(edge e[],int n)
{
	if(debug==1) printf("Print Data\n");
	for(int i=0;i<n*n;i++)
		printf("%d head: %d tail: %d weight:%.2f status:%d\n",i+1,e[i].h,e[i].t,e[i].w,e[i].d);
}

void printSol(edge e[],int checked[],float sol,int n)
{
	if(debug==2) printf("print Solve\n");
	printf("Solve:\n");
	for(int i=0;i<n*n-2;i++)
	{
		if(e[i].h!=e[i].t&&checked[i]==1)
		{
			printf("%d %d %.2f\n",e[i].h,e[i].t,e[i].w);
			if(debug==2) printf("Status: %d\n",e[i].d);
		}
	}
	printf("Sum: %.2f",sol);
}

int FindPivot(edge a[], int i,int j)
{
	keytype firstkey;
	int k ;
	k=i+1;
	firstkey=a[i].w;
	while (k<=j&&a[k].w==firstkey) k++;
	if(k>j) return -1;
	else
		if(a[k].w>firstkey) return k;
		else return i;
}

int Partition(edge a[],int i,int j,keytype pivot)
{
	int L,R;
	L=i;
	R=j;
	while(L<=R)
	{
		while(a[L].w<pivot) L++;
		while(a[R].w>=pivot) R--;
		if(L<R) swap(&a[L],&a[R]);
	}
	return L;
}

void QuickSort(edge a[],int i,int j)
{
	keytype pivot;
	int pivotIndex,k;
	pivotIndex=FindPivot(a,i,j);
	if(pivotIndex!=-1)
	{
		pivot=a[pivotIndex].w;
		k=Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}

//Greedy
float tspGreedy(edge e[],int checked[],int dd[],int n)
{
	if(debug==2) printf("Greedy\n");
	float sum=0.0;
	dd[e[n].h]=1;
	for(int i=0;i<n*n;i++)
	{
		if(debug==2) printf("%d\n",i+1);
		if(e[i].h!=e[i].t&&checked[i]==0&&e[i].d==0&&dd[e[i].t]==0)
		{
			deleteReEdge(e,n,i);
			checked[i]=1;
			e[i].d=1;
			dd[e[i].t]=1;
			sum=sum+e[i].w;
		}
	}
	return sum;
}

//main
int main()
{
	edge e[100];
	initEdge(e);
	int n,checked[100],dd[100];
	resetArray(checked,dd,100);
	readData(e,&n);
	QuickSort(e,0,n*n-1);
	if(debug==2||debug==1) printData(e,n);
	float sol=tspGreedy(e,checked,dd,n);
	printSol(e,checked,sol,n);
	return 0;
}