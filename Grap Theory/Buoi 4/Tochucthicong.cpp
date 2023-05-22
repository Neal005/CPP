#include<stdio.h>
typedef struct
{
	int A[100][100];
	int m,n;
} dothi;
void khoitao(dothi *G, int n)
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			G->A[i][j]=0;
		}
	}
	G->n=n+2;
}
void themcung(dothi *G,int u,int v)
{
	G->A[u][v]=1;
	G->m++;
}
int bac[100];
int hang[100];
int dd[100];
int tamhoan[100];
int l[100];
int t[100],T[100];
//void tinhbac(dothi G)
//{
//	for(int i=1;i<=G.n;i++)
//	{
//		for(int j=1;j<=G.n;j++)
//		{
//			if(G.A[j][i]==1) bac[i]++;
//		}
//	}
//}
//void inbac(dothi G)
//{
//	for(int i=1;i<=G.n;i++)
//	{
//		printf("%d ",bac[i]);
//	}
//	printf("\n");
//}
int hoantat(dothi G)
{
	int dem=0;
	for(int i=1;i<=G.n;i++)
	{
		if(dd[i]==1) dem++;
	}
	if(dem==G.n) return 1;
	return 0;
}
void xephang(dothi G)
{
	int temp=0;
	do
	{
		for(int i=1;i<=G.n;i++)
		{
			if(bac[i]==0&&dd[i]!=1&&tamhoan[i]!=1)
			{
				hang[i]=temp;
				dd[i]=1;
				for(int j=1;j<=G.n;j++)
				{
					if(G.A[i][j]==1)
					{
						bac[j]--;
						tamhoan[j]=1;
					}
				}
			}
		}
		for(int i=1;i<=G.n;i++) tamhoan[i]=0;
		temp++;
	} while(!hoantat(G));
}
int hangmax(int n)
{
	int max=0;
	for(int i=1;i<=n;i++)
	{
		if(hang[i]>max) max=hang[i];
	}
	return max;
}
void tinh_t(dothi G,int max)
{
	for(int i=0;i<=max;i++)
	{
		for(int j=1;j<=G.n;j++)
		{
			int max1=0;
			if(hang[j]==i+1&&t[j]==0)
			{
				for(int k=1;k<=G.n;k++)
				{
					if(G.A[k][j]==1)
					{
						t[j]=l[k]+t[k];
						if(t[j]>max1) max1=t[j];
					}
				}
				t[j]=max1;
			}
		}
	}
	T[G.n]=t[G.n];
}
void tinh_T(dothi G,int max)
{
	int min;
	for(int i=max;i>=0;i--)
	{
		for(int j=1;j<=G.n;j++)
		{
			if(hang[j]==i&&T[j]==0&&j!=G.n-1)
			{
				min=999999;
				for(int k=1;k<=G.n;k++)
				{
					if(G.A[j][k])
					{
						T[j]=T[k]-l[j];
						if(T[j]<min) min=T[j];
					}
				}
				T[j]=min;
			}
		}
	}
}
int main()
{
	dothi G;
	int n,u,v;
	for(int i=0;i<100;i++)
	{
		bac[i]=0;
		hang[i]=0;
		dd[i]=0;
		tamhoan[i]=0;
		l[i]=0;
		t[i]=0;
		T[i]=0;
	}
	scanf("%d",&n);
	khoitao(&G,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u);
		l[i]=u;
		do
		{
			scanf("%d",&v);
			if(v>0)
			{
				bac[i]++;
				themcung(&G,v,i);
			}
		} while(v>0);
	}
//	tinhbac(G);
//	inbac(G);
	xephang(G);
	int max=hangmax(G.n-2);
	t[G.n-1]=0;
	T[G.n-1]=0;
	hang[G.n]=max+1;
	for(int i=1;i<=G.n-2;i++)
	{
		if(hang[i]==0)
		{
			themcung(&G,G.n-1,i);
		}
		if(hang[i]==max)
		{
			themcung(&G,i,G.n);
		}
	}
	tinh_t(G,max);
	tinh_T(G,max);
	printf("%d\n",t[G.n]);
	for(int i=1;i<=n+2;i++)
	{
		printf("%d-%d\n",t[i],T[i]);
	}
}