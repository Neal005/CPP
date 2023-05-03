#include<stdio.h>
#include<math.h>
void sort(int A[],int n)
{
	int i,i1,i2,i3=0,tem;
	for(i=0;i<=n-1;i++)
	{
		for(i1=n-1;i1>=i+1;i1--)
		{
			if(A[i1]<A[i1-1])
			{
				tem=A[i1];
				A[i1]=A[i1-1];
				A[i1-1]=tem;
				for(i2=0;i2<=n-1;i2++)
				{
					if(i2==0) 
					{
						if(i3+1<10) printf("(0%d) ",i3+1);
						else
						printf("(%d) ",i3+1);
					}
					printf("%d ",A[i2]);
					if(i2==n-1) printf("\n");
				}
				i3++;
			}
		}
	}
}
int main()
{
	int A[100],i,n;
	printf("Nhap so phan tu trong day: \n");
	scanf("%d",&n);
	printf("Nhap day so can sap xep: \n");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("------------------------\n");
	sort(A,n);
	printf("------------------------\n");
	printf("Day sau khi sap xep la: \n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d ",A[i]);
	}
}