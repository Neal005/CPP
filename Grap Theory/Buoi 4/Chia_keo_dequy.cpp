#include<stdio.h>
#define debug 0
typedef struct
{
	int A[100][100];
	int m,n;
} dothi;
void khoitao(dothi *G, int n)
{
	for(int i=1;i<100;i++)
		for(int j=1;j<100;j++)
			G->A[i][j]=0;
	G->n=n;
}
void themcung(dothi *G,int u, int v)
{
	G->A[u][v]=1;
	G->m++;
}
int hang[100];
void reset_array()
{
	for(int i=1;i<100;i++)
		hang[i]=-1;
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
int main()
{
	dothi G;
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	khoitao(&G,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		themcung(&G,u,v);
	}
	reset_array();
	int sum=0;
	for(int i=1;i<=n;i++)
		printf("%d\n",xephang(G,i)+1);
	for(int i=1;i<=n;i++)
		sum+=hang[i]+1;
	printf("%d\n",sum);
	if(debug)
	{
		printf("\nhang[]: ");
		for(int i=1;i<=n;i++) printf("%d ",hang[i]+1);
		printf("\n");
	}
}