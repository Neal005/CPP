#include<stdio.h>
#include<math.h>
int factorial(int n)
{
	if(n==0) return 1;
	return n*factorial(n-1);
}
int main()
{
	int n;
	printf("Nhap so can tim giai thua: \n");
	scanf("%d",&n);
	printf("Giai thua cua %d la: %d",n,factorial(n));
}