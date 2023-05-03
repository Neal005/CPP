#include<stdio.h>
int main()
{
	int i,j,m=3;
	int n;
	printf("Nhap so hang cua tam giac pascal: ");
	scanf("%d",&n);
	if(n>32) 
	{
		printf("So hang phai be hon 32 vi may deo coi noi tam giac pascal tren 32 hang dau =]]\n*Khinh bi*");
	}
	else
	{
		int A[n][n];
		A[0][0]=1;
		A[1][0]=1;
		A[1][1]=1;
		for(i=2;i<n;i++)
		{
			A[i][0]=1;
			m++;
			for(j=1;j<m;j++)
			{
				if(j==m-2)
				{
					A[i][j]=A[i-1][j-1];
				}
				else
				{
					A[i][j]=A[i-1][j-1]+A[i-1][j];
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				printf("%d ",A[i][j]);
			}
			printf("\n");
		}
	}
}