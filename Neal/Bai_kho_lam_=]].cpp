#include<stdio.h>
#include<string.h>
int main()
{
	int A[48];
	char c[100];
	fgets(c,sizeof(c),stdin);
	for(int i=0;i<48;i++)
	{
		A[i]=0;
	}
	for(int i=0;i<=23;i++)
	{
		for(int j=0;j<=strlen(c);j++)
		{
			if(c[j]=='a'+i) A[i]++;
			if(c[j]=='a'+i-32) A[i+24]++;
		}
	}
	for(int i=0;i<24;i++)
	{
		if(A[i]>0) printf("%c: %d\n",'a'+i,A[i]);
	}
	printf("\n");
	for(int i=24,temp=0;i<48;i++)
	{
		if(A[i]>0) printf("%c: %d\n",'A'+temp,A[i]);
		temp++;
	}
}