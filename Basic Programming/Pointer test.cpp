#include<stdio.h>
int main()
{
	int *p,a=10;
	p=&a;
	printf(" p = %d -p da duoc gan dia chi cua a\n*p = %d -Noi dung cua dia chi a\n&p = %d -dia chi cua p\n a = %d -noi dung cua a\n&a = %d -& la dia chi",p,*p,&p,a,&a);
}