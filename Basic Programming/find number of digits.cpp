#include <stdio.h>
#include <math.h>
int main()
{
	int i=1,n,n2=1;
	scanf("%d",&n);
	while (n/10!=0)
	{
		n2=n/10;
		n=n2;
		i++;
	}
	printf("Number of digits: %d",i);
}