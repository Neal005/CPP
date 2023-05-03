#include<stdio.h>
#include<math.h>
int prime(int n)
{
	int i;
	if (n<2) return 0;
    for(i=2;i<=(n-1);i++)
	{
        if (n%i==0) return 0; 
    }
    return 1;
}
int main()
{
	int A[100],i,n,dem;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	scanf("%d",&A[i]);
	for(i=0;i<=n-1;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	dem=0;
	for(i=0;i<=n-1;i++)
	{
		if(prime(A[i])) dem++;
	}
	printf("%d\n",dem);
	for(i=0;i<=n-1;i++)
	{
		if(prime(A[i])) printf("%d ",A[i]);
	}
}