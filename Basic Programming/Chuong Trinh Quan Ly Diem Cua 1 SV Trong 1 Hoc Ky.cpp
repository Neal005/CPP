#include <stdio.h>
#include <math.h>
int main()
{
	float a,Max,Min,TB;
	int i=1,n;
	scanf("%d",&n);
	TB=0;
	a=0;
	Max=0;
	Min=10;
	while (i<=n)
	{	
		scanf("%f",&a);
		TB=TB+a;
		if(a>=Max)Max=a;
		if (a<=Min)Min=a;	
		i++;
	}
	TB=TB/(i-1);
	printf("%.2f ",TB);
	printf("%.2f ",Max);
	printf("%.2f ",Min);
}