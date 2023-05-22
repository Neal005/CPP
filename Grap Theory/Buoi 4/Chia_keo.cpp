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
	G->n=n;
}
void themcung(dothi *G,int u,int v)
{
	G->A[v][u]=1;
	G->m++;
}
int bac[100];
int hang[100];
int dd[100];
int tamhoan[100];
int sokeo[100];
void tinhbac(dothi G)
{
	for(int i=1;i<=G.n;i++)
	{
		for(int j=1;j<=G.n;j++)
		{
			if(G.A[j][i]==1) bac[i]++;
		}
	}
}
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
				sokeo[i]=hang[i]+1;
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
int tongsokeo(dothi G)
{
	int sum=0;
	for(int i=1;i<=G.n;i++)
	{
		sum+=sokeo[i];
	}
	return sum;
}
int main()
{
	dothi G;
	int n,m,u,v;
	for(int i=0;i<100;i++)
	{
		bac[i]=0;
		hang[i]=0;
		dd[i]=0;
		tamhoan[i]=0;
		sokeo[i]=0;
	}
	scanf("%d%d",&n,&m);
	khoitao(&G,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		themcung(&G,u,v);
		//Them cung nguoc voi du lieu duoc nhap vao
	}
	tinhbac(G);
	xephang(G);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",sokeo[i]);
	}
	printf("%d",tongsokeo(G));
}