#include<stdio.h>
#include<math.h>

double GCD(double a,double b) 
{
	double r;
	if (b!=0) 
	{
		r = a%b;
		return GCD(abs(b),abs(r));
	} 
	else return a;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",GCD(a,b));
}