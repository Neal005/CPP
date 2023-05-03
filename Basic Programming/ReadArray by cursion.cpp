#include<stdio.h>
#include<math.h>
void readArray(int A[],int n)
{
	if(n==0);
    else
    {
    	readArray(A,n-1);
		printf("%d ",A[n-1]);
    }
}
int main()
{
	int i,n,A[50];
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	scanf("%d",&A[i]);
	readArray(A,n);
}