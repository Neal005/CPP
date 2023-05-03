#include<stdio.h>
#include<math.h>
int getFibo(long long int A[],long long int n)
{
	int i;
	if (n==0) return A[0]=1;
	if (n==1) return A[1]=1;
	A[0]=1;
	A[1]=1;
	long long int tem,s1=1,s2=1;
	for(i=2;i<=n;i++)
	{
		A[i]=s1+s2;
		tem=s1;
		s1=A[i];
		s2=tem;
	}
}
int main()
{
	long long int A[50];
	long long int i,n;
	scanf("%lld",&n);
	getFibo(A,n);
	for(i=0;i<=n;i++)
    printf("%lld ",A[i]);
}
