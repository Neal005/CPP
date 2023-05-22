#include<stdio.h>
typedef struct
{
	int A[100][100];
	int m,n;
} dothi;
void khoitaoG(dothi *G)
{
	int i,j;
	G->m=0;
	G->n=0;
	for(i=1;i<100;i++)
	{
		for(j=1;j<100;j++)
		{
			G->A[i][j]=0;
		}
	}
}
void themcung(dothi *G, int x, int y, int z)
{
	G->A[x][y]=z;
	G->A[y][x]=z;
	G->m++;
}
int ds[100],dd[100],p[100];
int caykhung(dothi G)
{
	int sum=0;
	for(int i=1;i<G.n;i++)
	{
		ds[0]=0;
		for(int j=1;j<=G.n;j++)
		{
			if(i!=j&&G.A[j][i]!=0&&dd[j]==0)
			{
				ds[j]=G.A[j][i];
				ds[0]++;
			}
		}
		if(ds[0]==0);
		else
		{
			int min=999999,temp;
			for(int j=1;j<=G.n;j++)
			{
				if(ds[j]!=0&&ds[j]<min)
				{
					min=ds[j];
					temp=j;
				}
			}
			G.A[i][temp]=0;
			G.A[temp][i]=0;
			dd[temp]=1;
			p[i]=temp;
			sum+=min;
		}
		for(int j=0;j<=G.n;j++)
		{
			ds[j]=0;
		}
	}
	return sum;
}
int main()
{
	dothi G;
	khoitaoG(&G);
	int m,n,u,v,z;
	for(int i=0;i<100;i++)
	{
		dd[i]=0;
		ds[i]=0;
		p[i]=0;
	}
	scanf("%d%d",&n,&m);
	G.n=n;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&z);
		themcung(&G,u,v,z);
	}
	int sum=caykhung(G);
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)
	{
		if(p[i]>0) printf("%d %d %d\n",i,p[i],G.A[p[i]][i]);
	}
}