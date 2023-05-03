#include<stdio.h>
#include<string.h>
int Demtu(char A[])
{
	int a=0,i=0;
	while(i<strlen(A)-1)
	{
		if(A[i]==' ')i++;
		else
		{
			a++;
			while(A[i]!=' ')
			{
				i++;
			}
		}
	}
	return a;
}
int main()
{
	char A[500];
	int i;
	printf("Nhap chuoi ky tu: \n");
	fgets(A,sizeof(A),stdin);
	for(i=1;i<strlen(A);i++)
	printf("-");
	printf("---\n");
	printf("%s",A);
	printf("%d",Demtu(A));
}