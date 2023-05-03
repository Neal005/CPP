#include <stdio.h>
int main()
{
	int n1,n2,i1,i2,i3,n,i;
	scanf("%d",&n);
	n1=1;
	n2=n-1;
	for (i=1;i<=n;i++)
		printf("*");
	printf("\n");
	for (i1=1;i1<=n-1;i1++)
	{
		for (i2=1;i2<=n1;i2++)
		{
			printf(" ");
		}
		for (i3=n2;i3>=1;i3--)
			{
				printf("*");
			}
		n1++;
		n2--;
		printf("\n");
	}
}