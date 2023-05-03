#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,m,i1,n1,i2;
	scanf("%d%d",&m,&n);
	n1=n;
	i2=1;
	for (i=1;i<=m;i++)
	{
		for (i1=i2;i1<=n1;i1++)
		{
			printf("%d ",i1);
		}
		i2=n1+1;
		n1=n1+n;
		printf("\n");
	}
}