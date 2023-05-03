#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int c=3,t;
	char chon;
	printf("	***THE HA NOI TOWER QUIZ***\n");
	do
	{
		printf("- Floor of Ha Noi tower: ");scanf("%d",&t);
		fflush(stdin);
		if(t<=0)
		{
			system("cls");
			printf("The numbers of the floor must more than 1\n");
		}
	} while(t<=0);
	int A[t][c];
	int H[c];
	int C[c];
	int c1,c2;
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
	int i,j,kt=0;
	do
	{
		do
		{
			do
			{
				printf("from column: ");scanf("%c",&c2);fflush(stdin);
				printf("to column: ");scanf("%c",&c1);fflush(stdin);
				if(c2<'A'&&c2>'C'||c2<'1'&&c2>'3'&&c1<'A'&&c1>'C'||c1<'1'&&c1>'3')
				{
					system("cls");
					printf("*Error! Plz type a right column!\n");
				}
			}while(c2<'A'&&c2>'C'||c2<'1'&&c2>'3'&&c1<'A'&&c1>'C'||c1<'1'&&c1>'3');
			if(c2=='1')i=0;
			if(c2=='2')i=1;
			if(c2=='3')i=2;
			if(c1=='1')j=0;
			if(c1=='2')j=1;
			if(c1=='3')j=2;
			for(i=0;i<3;i++)
			{
				if(C[i]==c2) break;
			}
			for(j=0;j<3;j++)
			{
				if(C[j]==c1) break;
			}
			if(H[j]==0) 
			{
					kt=1;
			}
			else
			{
				if(A[H[j]-1][P[j]]-A[H[i]-1][P[i]]>=1) kt=1;
			}
			if(kt==0)
			{
				system("cls");
				printf("*Error! Type again!\n");
			}
		} while(kt==0);
		if(H[j]==0)
		{
			A[H[j]][P[j]]=A[H[i]-1][P[i]];
			A[H[i]-1][P[i]]=0;
			H[i]--;
			H[j]++;
		}
		
	}while(H[c-1]!=t);
	
}