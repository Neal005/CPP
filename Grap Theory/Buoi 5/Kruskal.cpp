#include<stdio.h>
typedef struct
{
	int dau, duoi;
	int trongso;
} cung;
typedef struct
{
	cung A[100];
	int m,n;
} dothi;
void khoitaoG(dothi *G,int n)
{
	G->m=0;
	G->n=n;
	for(int i=0;i<100;i++)
	{
		G->A[i].dau=0;
		G->A[i].duoi=0;
		G->A[i].trongso=0;
	}
}
void themcung(dothi *G, int x, int y, int z)
{
	G->A[G->m+1].dau=x;
	G->A[G->m+1].duoi=y;
	G->A[G->m+1].trongso=z;
	G->m++;
}
int dd[100],ct[100],shopee[100];
int cochutrinh(dothi G, int x)
{
	for(int i=1;i<=G.m;i++)
	{
		if(dd[i]==1)
		{
			if(ct[G.A[i].duoi]>ct[G.A[i].dau]) ct[G.A[i].duoi]=ct[G.A[i].dau];
			else ct[G.A[i].dau]=ct[G.A[i].duoi];
		}
	}
	dd[x]=1;
	if(ct[G.A[x].duoi]==ct[G.A[x].dau]) return 1;
	for(int i=1;i<=G.m;i++)
	{
		if(dd[i]==1)
		{
			if(ct[G.A[i].duoi]>ct[G.A[i].dau]) ct[G.A[i].duoi]=ct[G.A[i].dau];
			else ct[G.A[i].dau]=ct[G.A[i].duoi];
		}
	}
	return 0;
}
int caykhung(dothi G)
{
	int sum=0,chutrinh;
	dd[1]=1;
	if(ct[G.A[1].duoi]>ct[G.A[1].dau]) ct[G.A[1].duoi]=ct[G.A[1].dau];
	else ct[G.A[1].dau]=ct[G.A[1].duoi];
	sum+=G.A[1].trongso;
	for(int i=2;i<=G.m;i++)
	{
		chutrinh=cochutrinh(G,i);
		if(!chutrinh)
		{
			sum+=G.A[i].trongso;
		}
		else
		{
			shopee[i]=1;
		}
	}
	return sum;
}
void sapxep(dothi *G)
{
	cung temp;
	for(int i=1;i<=G->m-1;i++)
	{
		for(int j=i+1;j<=G->m;j++)
		{
			if(G->A[i].trongso>G->A[j].trongso)
			{
				temp=G->A[i];
				G->A[i]=G->A[j];
				G->A[j]=temp;
			}
		}
	}
}
int main()
{
	dothi G;
	int m,n,u,v,z;
	for(int i=0;i<100;i++)
	{
		dd[i]=0;
		ct[i]=i;
		shopee[i]=0;
	}
//	freopen("dt.txt","r",stdin);
	scanf("%d%d",&n,&m);
	khoitaoG(&G,n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&z);
		themcung(&G,u,v,z);
	}
	sapxep(&G);
	int sum=caykhung(G);
	printf("%d\n",sum);
	for(int i=1;i<=m;i++)
	{
		if(shopee[i]!=1)
		{
			if(G.A[i].dau<G.A[i].duoi) printf("%d %d %d\n",G.A[i].dau,G.A[i].duoi,G.A[i].trongso);
			else printf("%d %d %d\n",G.A[i].duoi,G.A[i].dau,G.A[i].trongso);
		}
	}
}