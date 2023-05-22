#include<stdio.h>
typedef struct
{
	int A[100];
	int dau,duoi;
} hangdoi;
void khoitaoQ(hangdoi *Q)
{
	for(int i=0;i<100;i++)
	{
		Q->A[i]=0;
	}
	Q->dau=Q->duoi=0;
}
int lay(hangdoi *Q)
{
	int x;
	if(Q->dau!=Q->duoi)
	{
		x=Q->A[Q->dau];
		Q->dau++;
		return x;
	}
	return 0;
}
void themQ(hangdoi *Q, int x)
{
	Q->A[Q->duoi]=x;
	Q->duoi++;
}
int dsrong(hangdoi Q)
{
	if(Q.dau==Q.duoi) return 1;
	return 0;
}
typedef struct
{
	int A[100][100];
	int m,n;
} dothi;
void khoitaoG(dothi *G, int n)
{
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			G->A[i][j]=0;
		}
	}
	G->m=0;
	G->n=n;
}
void themcung(dothi *G, int u,int v,int z)
{
	G->A[u][v]=z;
	G->m++;
}
int y[100],x1[100],flow[100],p[100],maxflow;
void tangluong(dothi *G, int x)
{
	if(x>1&&G->A[p[x]][x]>0)
	{
		G->A[p[x]][x]=G->A[p[x]][x]-flow[G->n];
//		printf("%d %d\n",p[x],x);
//		printf("%d\n",G->A[p[x]][x]);
//		printf("%d\n",flow[G->n]);
		tangluong(G,p[x]);
	}
}
void Maxflow(dothi G)
{
	int dd[100],x;
	hangdoi Q;
	khoitaoQ(&Q);
	do
	{
		for(int i=0;i<100;i++) dd[i]=0;
		themQ(&Q,1);
		flow[1]=999999;
		do
		{
			x=lay(&Q);
			for(int i=1;i<=G.n;i++)
			{
				if(G.A[x][i]>0&&dd[i]==0)
				{
					if(G.A[x][i]>flow[x]) flow[i]=flow[x];
					else flow[i]=G.A[x][i];
					themQ(&Q,i);
					p[i]=x;
				}
			}
			dd[x]=1;
		} while(dd[G.n]==0&&!dsrong(Q));
		if(dd[G.n]==1&&G.A[p[x]][x]>0)
		{
			tangluong(&G,G.n);
//			printf("%d\n",G.A[1][3]);
//			printf("%d\n",flow[G.n]);
//			printf("%d\n",maxflow);
			maxflow=maxflow+flow[G.n];
		}
	} while(dd[G.n]==1);
	for(int i=1;i<=G.n;i++)
	{
		if(dd[i]==1)
		{
			x1[0]++;
			x1[x1[0]]=i;
		}
		else
		{
			y[0]++;
			y[y[0]]=i;
		}
	}
}
int main()
{
	dothi G;
	int n,m,u,v,z;
	scanf("%d%d",&n,&m);
	khoitaoG(&G,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&z);
		themcung(&G,u,v,z);
	}
	for(int i=0;i<100;i++)
	{
		x1[i]=0;
		y[i]=0;
		p[i]=i;
		flow[i]=0;
	}
	maxflow=0;
	Maxflow(G);
	printf("Max flow: %d\n",maxflow);
	printf("X0: ");
	for(int i=1;i<=x1[0];i++) printf("%d ",x1[i]);
	printf("\n");
	printf("Y0: ");
	for(int i=1;i<=y[0];i++) printf("%d ",y[i]);
}