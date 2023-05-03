#include<stdio.h>
#include<math.h>
void makeReverse(int A[],int n)
{
	int B[n],i1=n-1,i=0;
	while (i<=n-1)
	{
		B[i1]=A[i];
		i++;
		i1--;
	}
	for(i=0;i<=n-1;i++)
	 A[i]=B[i];
}
int main()
{
	int A[50];
	int i,n;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&A[i]);
	makeReverse(A,n);
	for(i=0;i<=n-1;i++)
    	printf("%d ",A[i]);
}