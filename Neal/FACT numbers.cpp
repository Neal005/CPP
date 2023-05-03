#include<stdio.h>
#include<math.h>
#include<windows.h>
int Dem(long long int n)
{
	int i=1,n2=1;
	while (n/10!=0)
	{
		n2=n/10;
		n=n2;
		i++;
	}
	return i;
}
void FACT()
{
	long long int n;
	char DK='1';
	int DK1=1;
	long long int i3=0;
	while(DK=='1')
	{
		printf("Nhap so can FACT: ");scanf("%lld",&n);
		int am=0;
		if(n<0)
		{
		    am=1;
		    n*=-1;
		}
		printf("Ket qua: \n");
		if(n==20112018&&i3==3) printf("Ki niem ngay dau yeu nhau cua Nguyen Le Hoang Luc va Tran Thu Ngan!\n");
		if(n==23092003&&i3==3) printf("Nguyen Le Hoang Luc\n");
		if(n==13022003&&i3==3) printf("Tran Thu Ngan\n");		printf("______________________________________________________________________\n");
		long long int i=2;
		int i1=0,i2,n2,a=0;
		if(am==1)
		{
		    printf("-");
		    i1++;
		}
		if(n==1)
		{
		    printf("(1)");
		    i1+=3;
		}
		if(n==0)
		{
		    printf("(0)");
		    i1+=3;
		}
		while(n!=1&&n!=0)
		{
			if(n%i==0)
			{
				while(n%i==0)
				{
					n=n/i;
					if(a==0)
					{
						printf("(%lld",i);
						i1+=Dem(i)+1;
					}
					a++;
				}
				if(a>1) 
				{
					printf("^%d)",a);
					i1+=Dem(a)+2;
				}
				if(a<=1) 
				{
					printf(")");
					i1++;
				}
				if(n!=1) 
				{
					printf("x");
					i1++;
				}
				a=0;
				i++;
			}
			else i++;
		}
		for(i=1;i<71-i1;i++)
		{
			printf(" ");
		}
		printf("|\n");
		printf("______________________________________________________________________|\n");
		while(DK1==1)
		{
			printf("Tiep tuc?\n	Type 1 to continues		Type 2 to cancel\n");
			fflush(stdin);
			scanf("%c",&DK);
			fflush(stdin);
			if(DK=='1')
			{ 
				system("cls");
				DK1=0;
				i3++;
			}
			if(DK=='2') DK1=0;
			if(DK!='1'&&DK!='2')
			{
			    system("cls");
			    printf("*Nhap 1 hoac 2 nhap cai khac an cac a?\n--------------------------------------------\n");
			}
		}
		DK1=1;
	}
}
int main()
{
	FACT();
}