#include<stdio.h>
#include<math.h>
struct ChuNhat
{
	float ChieuDai;
	float ChieuRong;
};
int main()
{
	int m,n,i,i1,i2,i3,l1,l2,l=0;
	float Max1,Max2;
	printf("Nhap so hinh chu nhat: ");scanf("%d",&n);
	float a[n],b[n];
	struct ChuNhat A[n];
	for(i=0;i<n;i++)
	{
		printf("Nhap chieu dai hinh chu nhat thu %d: ",i+1);
		scanf("%f",&A[i].ChieuDai);
		printf("Nhap chieu rong hinh chu nhat thu %d: ",i+1);
		scanf("%f",&A[i].ChieuRong);
		printf("----------------------------------------\n");
		a[i]=A[i].ChieuDai*A[i].ChieuRong;
		printf(" ");
		for(i1=1;i1<=int(A[i].ChieuRong);i1++)
		printf("__");printf("\n");
		for(i1=1;i1<=int(A[i].ChieuDai)-1;i1++)
		{
			printf("|"); for(i2=2;i2<=int(A[i].ChieuRong)*2+1;i2++) printf(" ");printf("|\n");
		}
		printf("|");
		for(i1=1;i1<=int(A[i].ChieuRong);i1++)
		printf("__");printf("|");printf("\n\n");printf("----------------------------------------\n");
	}
	m=n-1;
	Max1=0;
	Max2=0;
	for(i=0;i<(n+1)/2;i++)
	{
		if(a[i]>=Max1) 
		{
			Max1=a[i];
			i1=i;
		}
		if(a[m]>=Max2) 
		{
			Max2=a[m];
			i2=m;
		}
		m--;
	}
	if(Max2>Max1) 
	{
		Max1=Max2;
		i1=i2;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==Max1)
		{
			b[l]=i;
			l++;
			l1=l;
		}
	}
	m=0;
	printf("KET QUA O DAY!\n");
	for(i=1;i<=5;i++)
	printf("  |\n");
	printf("\\   /\n");
	printf(" \\ /\n");
	printf("  v\n");
	
	printf("Dien tich hinh chu nhat lon nhat la: \n");
	for(l=0;l<l1;l++)
		{
			i=b[l];
			if(l>=1)
			{
				for(l2=l-1;l2>=0;l2--)
				{
					i1=b[l2];
					if((A[i].ChieuDai==A[i1].ChieuDai)&&(A[i].ChieuRong==A[i1].ChieuRong))m=1;
				}	
				if(m==1);
				else
				{
					printf("- %.3fx%.3f = %.3f\n",A[i].ChieuDai,A[i].ChieuRong,Max1);
					printf(" ");
					for(i1=1;i1<=int(A[i].ChieuRong);i1++)
					printf("__");printf("\n");
					for(i1=1;i1<=int(A[i].ChieuDai)-1;i1++)
					{
						printf("|"); for(i2=2;i2<=int(A[i].ChieuRong)*2+1;i2++) printf(" ");printf("|\n");
					}
					printf("|");
					for(i1=1;i1<=int(A[i].ChieuRong);i1++)
					printf("__");printf("|");printf("\n\n");printf("----------------------------------------\n");
				}
				m=0;
			}
			else
			{
				printf("- %.3fx%.3f = %.3f\n",A[i].ChieuDai,A[i].ChieuRong,Max1);
				printf(" ");
				for(i1=1;i1<=int(A[i].ChieuRong);i1++)
				printf("__");printf("\n");
				for(i1=1;i1<=int(A[i].ChieuDai)-1;i1++)
				{
					printf("|"); for(i2=2;i2<=int(A[i].ChieuRong)*2+1;i2++) printf(" ");printf("|\n");
				}
				printf("|");
				for(i1=1;i1<=int(A[i].ChieuRong);i1++)
				printf("__");printf("|");printf("\n\n");printf("----------------------------------------\n");
			}
		}
}