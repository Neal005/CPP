#include <stdio.h>
#include <math.h>
int main ()
{
	int x1,x2,s,i,n;
	scanf("%d",&n);
	s=0;
	x1=0;
	x2=1;
	int temp=0;
	if (n==0) printf ("0");
	if (n==1) printf ("0, 1");
	if (n>1)
	{
		printf("0, 1, ");
		for (i=2;i<=n;i++)
		{
			s=x1+x2;
			temp = x2;
			x2=s;
			x1=temp;
			printf("%d",s);
			if (i<n) printf(", ");
		}
    }
}