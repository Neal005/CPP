#include<stdio.h>
void HNT(int n, char A,char B,char C)
{
	if(n==1) printf("%c -> %c\n",A,C);
	else
	{
		HNT(n-1,A,C,B);
		HNT(1,A,B,C);
		HNT(n-1,B,A,C);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	HNT(n,'A','B','C');
}