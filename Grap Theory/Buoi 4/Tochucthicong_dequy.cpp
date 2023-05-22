#include<stdio.h>
#define debug 0
typedef struct
{
	int A[100][100];
	int m,n;
	int l[100];
} dothi;
void khoitao(dothi *G, int n)
{
	for(int i=1;i<100;i++)
	{
		G->l[i]=0;
		for(int j=1;j<100;j++)
			G->A[i][j]=0;
	}
	G->n=n+2;
}
void themcung(dothi *G,int u, int v)
{
	G->A[u][v]=1;
	G->m++;
}
int hang[100],t[100],T[100],bac[100];
void reset_array()
{
	for(int i=1;i<100;i++)
	{
		t[i]=0;
		T[i]=999999;
		bac[i]=0;
		hang[i]=-1;
	}
}
int xephang(dothi G,int x)
{
	int Hang=-1;
	if(hang[x]>-1) return hang[x];
	else
	{
		for(int i=1;i<=G.n;i++)
		{
			if(G.A[x][i])
			{
				Hang=xephang(G,i);
			}
			if(hang[x]<Hang+1) hang[x]=Hang+1;
		}
	}
	return hang[x];
}
int tinh_t(dothi G,int x)
{
	if(t[x]>0) return t[x];
	else
	{
		for(int i=1;i<=G.n;i++)
		{
			if(G.A[i][x])
			{
				tinh_t(G,i);
				if(t[x]<t[i]+G.l[i]) t[x]=t[i]+G.l[i];
			}
		}
	}
	return t[x];
}
int tinh_T(dothi G,int x)
{
	if(T[x]<999999) return T[x];
	else
	{
		for(int i=1;i<=G.n;i++)
		{
			if(G.A[x][i])
			{
				tinh_T(G,i);
				if(T[x]>T[i]-G.l[x]) T[x]=T[i]-G.l[x];
			}
		}
	}
	if(x==G.n) T[x]=tinh_t(G,x);
	return T[x];
}
int main()
{
	dothi G;
	int n,u,v,alpha,beta;
	reset_array();
	scanf("%d",&n);
	khoitao(&G,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v);
		G.l[i]=v;
		do
		{
			scanf("%d",&u);
			if(u!=0)
			{
				themcung(&G,u,i);
				bac[i]++;
			}
		} while(u!=0);
	}
	alpha=n+1;
	beta=n+2;
	int dem;
	for(int i=1;i<=n;i++)
	{
		dem=0;
		if(bac[i]==0) themcung(&G,alpha,i);
		for(int j=1;j<=n;j++)
		{
			if(G.A[i][j])
			{
				dem++;
			}
		}
		if(dem==0) themcung(&G,i,beta);
	}
	t[alpha]=0;
	T[alpha]=0;
	if(debug)
	{
		for(int i=1;i<=n;i++)
		{
			if(G.A[alpha][i]) printf("Cong viec dau = %d\n",i);
			if(G.A[i][beta]) printf("Cong viec cuoi = %d\n",i);
		}
	}
	if(debug)
	{
		printf("G.l[]: ");
		for(int i=1;i<=G.n;i++)
			printf("%d ",G.l[i]);
		printf("\n");
	}
	printf("%d\n",tinh_t(G,beta));
	for(int i=1;i<=G.n;i++)
		printf("%d-%d\n",tinh_t(G,i),tinh_T(G,i));
}