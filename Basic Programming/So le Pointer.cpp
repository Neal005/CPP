#include<stdio.h>
#include<math.h>
#include<malloc.h>
void copyOddNumbers(int a[], int n, int b[], int *m)
{
	int i,i1=0;
	for(i=0;i<=n-1;i++)
	{
		if(a[i]%2==0);
		else 
		{
			b[i1]=a[i];
			i1++;
		}
	}
	*m=i1;
}
void printList(int a[], int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int i, n;
	int a[1000];
	printf("Nhap so phan tu: \n");
	scanf("%d",&n);
	printf("Nhap day so: \n");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[1000];
	int m;
	printf("-------------------\n");
	printList(a,n);
	copyOddNumbers(a,n,b,&m);
	printList(b,m);
}