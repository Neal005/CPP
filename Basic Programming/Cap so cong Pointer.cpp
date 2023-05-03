#include<stdio.h>
#include<math.h>
#include<malloc.h>
int *getSequence(int n, int d)
{
	int i;
	int *ar=(int*)malloc(n*sizeof(int));
	ar[0]=1;
	for(i=1;i<=n-1;i++)
	{
		ar[i]=ar[i-1]+d;
	}
	return ar;
}
int main()
{
	int *a;
	int n,d;
	printf("Nhap so phan tu: \n");
	scanf("%d",&n);
	printf("Nhap cong sai d: \n");
	scanf("%d",&d);
	int i;
	a=getSequence(n,d);
	for(i=0;i<=n-1;i++)
    	printf("%d ",a[i]);
	free(a);
}