#include<stdio.h>
#include<math.h>
#include<windows.h>
void Matrix()
{
	char chon;
	while(chon!='5')
	{
		chon='0';
		int a,b,m=0,n=0,rA=0,rA1=0;
		while(m<=0||n<=0)
		{
			printf("Enter matrix A* of size m x n:\nEnter m: "); scanf("%d",&m);fflush(stdin);
			printf("Enter n: "); scanf("%d",&n);fflush(stdin);
			if(m<=0||n<=0) 
			{
				system("cls");
				printf("*Only enter numbers greater than 0 (m, n > 0)\n");
			}
		}
		double temp,A[m][n];
		char B[n];
		double B1[n];
		for(int i=0;i<m;i++)
		{
			printf("Enter the %dth row: ",i+1);
			for(int j=0;j<n;j++)
			{
				do
				{
					B1[j]=1;
					B[j]=' ';
					scanf("%lf",&A[i][j]);
					scanf("%c",&B[j]);
					if(B[j]=='/')
					scanf("%lf",&B1[j]);
					if(B[j]=='/')
					{
						if(B1[j]!=0)A[i][j]=A[i][j]/B1[j];
						else 
						{
							printf("The denominator must be not equal to zero!\n*Please enter the %dth row again: ",i+1);
							fflush(stdin);
						}
					}
				} while(B1[j]==0);
			}
			fflush(stdin);
		}
		double A2[m][n];
		for(int i=0;i<m;i++)
		{
			for(int i1=0;i1<n;i1++)
			{
				A2[i][i1]=A[i][i1];
			}
		}
		int num=m;
		int hang0;
		for(int i1=0;i1<m;i1++)
		{
			hang0=0;
			for(int i11=0;i11<n;i11++)
			{
				if(A[i1][i11]==0) hang0++;
			}
			if(hang0==n)
			{
				hang0=0;
				for(int i0=0;i0<n;i0++)
				{
					if(A[num-1][i0]==0) hang0++;
				}
				if(hang0==n) num--;
				if(num>i1)
				{
					for(int i111=0;i111<n;i111++)
					{
						double temp1=A[i1][i111];
						A[i1][i111]=A[num-1][i111];
						A[num-1][i111]=temp1;
					}
				}
			}
		}
		//Giai doan 1
		for(int i=0;i<n;i++)
		{
			for(int i1=i;i1<m-1;i1++)
			{
				if(A[i1][i]!=0)
				{                                                                           
					for(int i11=i+1;i11<m;i11++)
					{
						if(abs(A[i1][i])>abs(A[i11][i])&&A[i11][i]!=0)
						{
							for(int i111=i;i111<n;i111++)
							{
								double temp1=A[i1][i111];
								A[i1][i111]=A[i11][i111];
								A[i11][i111]=temp1;
							}
						}
					}
				}
				if(A[i1][i]==0)
				{
					for(int num=m-1;num>i1;num--)
					{
						if(A[num][i]!=0)
						{
							for(int i11=i;i11<n;i11++)
							{
								double temp1=A[i1][i11];
								A[i1][i11]=A[num][i11];
								A[num][i11]=temp1;
							}
						}
					}
				}
				int khac0=0;
				while(true)
				{
					if(A[i][khac0]!=0) break;
					khac0++;
					if(khac0>=n) break;
				}
				double temp=A[i][khac0];
				for(int i2=i;i2<n;i2++)
				{
					if(A[i][i2]!=0) A[i][i2]=A[i][i2]/temp;
				}
				for(int i3=i+1;i3<m;i3++)
				{
					double temp1=A[i3][khac0];
					for(int i33=i;i33<n;i33++)
					{
						A[i3][i33]=A[i3][i33]-temp1*A[i][i33];
					}
				}
			}
			int num=m;
			int hang0;
			for(int i1=i;i1<m;i1++)
			{
				hang0=0;
				for(int i11=0;i11<n;i11++)
				{
					if(A[i1][i11]==0) hang0++;
				}
				if(hang0==n)
				{
					hang0=0;
					for(int i0=0;i0<n;i0++)
					{
						if(A[num-1][i0]==0) hang0++;
					}
					if(hang0==n) num--;
					if(num>i1)
					{
						for(int i111=0;i111<n;i111++)
						{
							double temp1=A[i1][i111];
							A[i1][i111]=A[num-1][i111];
							A[num-1][i111]=temp1;
						}
					}
				}
			}
		}
		double A1[m][n];
		for(int i=0;i<m;i++)
		{
			for(int i1=0;i1<n;i1++)
			A1[i][i1]=A[i][i1];
		}
		for(int i=0;i<m;i++)
		{
			for(int i1=0;i1<n-1;i1++)
			{
				if(A[i][i1]!=0)
				{
					rA++;
					break;
				}
			}
		}
		rA1=m;
		for(int i=m-1;i>=0;i--)
		{
			int hang0=0;
			for(int i1=0;i1<n;i1++)
			{
				if(A[i][i1]==0)
				{
					hang0++;
				}
			}
			if(hang0!=n) break;
			rA1--;
		}
		//Giai doan 2
		int khac0=0;
		while(true)
		{
			if(A[m-1][khac0]!=0) break;
			if(khac0>=n) break;
			khac0++;
		}
		double min=A[m-1][khac0];
		for(int i=0;i<n;i++)
		{
			if(min!=0&&A[m-1][i]!=0) A[m-1][i]=A[m-1][i]/min;
		}
		for(int i=0;i<m-1;i++)
		{	
			for(int i1=0;i1<=i;i1++)
			{
				int khac0=0;
				while(true)
				{
					if(A[i+1][khac0]!=0) break;
					if(khac0>=n) break;
					khac0++;
				}
				if(khac0<n)
				{
					double temp=A[i1][khac0];
					for(int i11=khac0;i11<n;i11++)
					{
						A[i1][i11]=A[i1][i11]-temp*A[i+1][i11];
					}
				}
			}
		}
		while(chon!='4'&&chon!='5')
		{
			int DK=1;
			printf("____________________________________________________________________________________\n");
			printf("*Choose operator:\n");
			while(DK==1)
			{
				printf("1. Ladder matrix	2. Shortened ladder matrix	3.Solution of the equation\n\n	4. Enter a new matrix		5. Exit\nChon: ");
				fflush(stdin);
				scanf("%c",&chon);
				if(chon!='1'&&chon!='2'&&chon!='3'&&chon!='4'&&chon!='5')
				{
					system("cls");
					printf("*Only choose operator 1 - 5, please choose again!\n");
				}
				else
				{
					DK=0;
				}
			}
			if(chon=='1')
			{
				system("cls");
				printf("Input Matrix: \n");
				for(int i=0;i<m;i++)
				{
					for(int i1=0;i1<n;i1++)
					{
						printf("%lf 	",A2[i][i1]);
					}
					printf("\n");
				}
				printf("Ladder matrix:\n");
				for(int i=0;i<m;i++)
				{
					for(int j=0;j<n;j++)
					{
						printf("%lf	",A1[i][j]);
					}
					printf("\n");
				}
			}
			if(chon=='2')
			{
				system("cls");
				printf("Input Matrix: \n");
				for(int i=0;i<m;i++)
				{
					for(int i1=0;i1<n;i1++)
					{
						printf("%lf 	",A2[i][i1]);
					}
					printf("\n");
				}
				printf("Shortened ladder matrix: \n");
				for(int i=0;i<m;i++)
				{
					for(int j=0;j<n;j++)
					{
						printf("%lf	",A[i][j]);
					}
					printf("\n");
				}
			}
			if(chon=='3')
			{
				system("cls");
				printf("Input Matrix: \n");
				for(int i=0;i<m;i++)
				{
					for(int i1=0;i1<n;i1++)
					{
						printf("%lf 	",A2[i][i1]);
					}
					printf("\n");
				}
				printf("Solution of the equation: \n");
				if(rA==rA1&&rA<n-1) printf("The equation has infinitely many solutions (IME)\n");
				else
				{
					if(rA<rA1) printf("system of equations with no solution (NS)\n");
					else
					{
						for(int i=0;i<n-1;i++)
						printf("x%d: %lf\n",i+1,A[i][n-1]);
					}
				}
			}
		}
		if(chon=='4') system("cls");
	}
}
int main()
{
	Matrix();
}