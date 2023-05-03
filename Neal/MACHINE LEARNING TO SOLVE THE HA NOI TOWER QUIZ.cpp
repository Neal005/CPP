#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int t,c;
	char chon;
	do
	{
		printf("		***MACHINE LEARNING TO SOLVE THE HA NOI TOWER QUIZ***\n");
		do
		{
			do
			{
				printf("- Floor of Ha Noi tower: ");scanf("%d",&t);
				fflush(stdin);
				printf("- Column for Ha Noi tower: ");scanf("%d",&c);
				fflush(stdin);
				if(t<=0)
				{
					system("cls");
					printf("The numbers of the column must more than 1\n");
				}
			} while(t<=0);
			if(c<3)
			{
				system("cls");
				printf("*The numbers of column must more than 3!\n");
			}
			if(c>24)
			{
				if(c>=3) system("cls");
				printf("*The numbers of column must less than 24!\n");
			}
		} while(c<3||c>24);
		int A[t][c];
		int H[c];
		char C[c];
		int P[t+1];
		for(int i=0;i<c;i++) C[i]='A'+i;
		for(int i=0;i<c;i++) H[i]=0;
		H[0]=t;
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<c;j++)
			{
				A[i][j]=0;
			}
		}
		for(int i=0;i<t;i++)
		{
			P[i+1]=0;
		}
		for(int i=0;i<t;i++)
		{
			A[i][0]=t-i;
		}
		printf("*Result:\n");
		int i=1;
		while(H[c-1]!=t)
		{
			int j=c-1;
			int done=0;
			while(j>=0&&done==0)
			{
				if(A[H[P[i]]-1][P[i]]==i&&H[j]!=0)
				{
					if(A[H[j]-1][j]-A[H[P[i]]-1][P[i]]>=1)
					{
						A[H[j]][j]=A[H[P[i]]-1][P[i]];
						A[H[P[i]]-1][P[i]]=0;
						H[P[i]]--;
						H[j]++;
						printf("%c ---> %c\n",C[P[i]],C[j]);
						P[i]=j;
						done=1;
					}
				}
				if(A[H[P[i]]-1][P[i]]==i&&H[j]==0)
				{
					A[H[j]][j]=A[H[P[i]]-1][P[i]];
					A[H[P[i]]-1][P[i]]=0;
					H[P[i]]--;
					H[j]++;
					printf("%c ---> %c\n",C[P[i]],C[j]);
					P[i]=j;
					done=1;
				}
				j--;
			}
			i++;
			if(i>t)i=1;
		}
		do
		{
			printf("Continue?\n1. Yup				2. Nope\n");
			scanf("%c",&chon);
			if(chon!='1'&&chon!='2')
			{
				system("cls");
				printf("*Just choose one or two!\n");
			}
		} while(chon!='1'&&chon!='2');
		if(chon=='1') system("cls");
	} while(chon=='1');
}