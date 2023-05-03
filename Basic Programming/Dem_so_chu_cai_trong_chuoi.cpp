#include<stdio.h>
#include<string.h>
int main()
{
	char A[500];
	int a=1,i;
	fgets(A,sizeof(A),stdin);
	for(i=0;i<=strlen(A);i++)
	if(A[i]==' '&&A[i+1]!=' ') a++;
	if(A[0]==' ') a=a-1;
	printf("%s",A);
	printf("%d",a);
}