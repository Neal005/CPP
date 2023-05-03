#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
	int i;
	if (n<2)
	{
    	return 0;
    }
    for(int i = 2; i < (n - 1);i++)
	{
        if (n%i== 0)
		{
            return 0;
        }   
    }
    return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
    if (isPrime(n))
    printf("So vua nhap la so nguyen to");
    else
    printf("So vua nhap khong phai la so nguyen to");
}