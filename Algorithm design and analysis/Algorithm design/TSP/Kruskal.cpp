#include<stdio.h>
#include<iostream>
#define debug 2

typedef struct
{
	int dau, duoi;
	float trongso;
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
void themcung(dothi *G,int x,int y,float z)
{
	G->A[G->m+1].dau=x;
	G->A[G->m+1].duoi=y;
	G->A[G->m+1].trongso=z;
	G->m++;
}
int dd[100],ct[100],shopee[100],cap[100];
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
			if(debug==2) printf("%d - %d\n",ct[G.A[i].dau],ct[G.A[i].duoi]);
		}
	}
	return 0;
}
float caykhung(dothi G)
{
	float sum=0.0,chutrinh;
	dd[1]=1;
	if(ct[G.A[1].duoi]>ct[G.A[1].dau]) ct[G.A[1].duoi]=ct[G.A[1].dau];
	else ct[G.A[1].dau]=ct[G.A[1].duoi];
	sum+=G.A[1].trongso;
	cap[G.A[1].dau]++;
	cap[G.A[1].duoi]++;
	for(int i=2;i<=G.m;i++)
	{
		chutrinh=cochutrinh(G,i);
		if(!chutrinh&&cap[G.A[i].dau]<2&&cap[G.A[i].duoi]<2)
		{
			sum+=G.A[i].trongso;
			cap[G.A[i].dau]++;
			cap[G.A[i].duoi]++;
			if(debug==2) printf("Dau %d: %d Duoi %d:%d\n",G.A[i].dau,cap[G.A[i].dau],G.A[i].duoi,cap[G.A[i].duoi]);
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

void readData(dothi *G)
{
	float z;
	FILE *f;
	f=fopen("TSP.txt","r");
	if(f==NULL) printf("Cant be open file\n");
	else
	{
		if(debug==1) printf("Opening file\n");
		fscanf(f,"%d",&G->n);
		if(debug==1) printf("So dinh: %d\n",G->n);
		for(int i=0;i<G->n;i++)
		{
			for(int k=i;k>=0;k--) fscanf(f,"%f",&z);
			for(int j=i;j<G->n;j++)
			{
				if(i!=j)
				{
					fscanf(f,"%f",&z);
					themcung(G,i+1,j+1,z);
				}
			}
		}
	}
	if(debug==1) printf("So cung: %d\n",G->m);
}

void printData(dothi G)
{
	for(int i=1;i<G.m;i++)
	{
		printf("%d %d %.2f\n",G.A[i].dau,G.A[i].duoi,G.A[i].trongso);
	}
}

int main()
{
	dothi G;
	int u,v,z;
	for(int i=0;i<100;i++)
	{
		dd[i]=0;
		ct[i]=i;
		shopee[i]=0;
		cap[i]=0;
	}
	khoitaoG(&G,0);
	readData(&G);
	if(debug==1) printData(G);
	sapxep(&G);
	if(debug==2) printData(G);
	float sum=caykhung(G);
	printf("%.2f\n",sum);
	for(int i=1;i<=G.m;i++)
	{
		if(shopee[i]!=1)
		{
			if(G.A[i].dau<G.A[i].duoi) printf("%d %d %.2f\n",G.A[i].dau,G.A[i].duoi,G.A[i].trongso);
			else printf("%d %d %.2f\n",G.A[i].duoi,G.A[i].dau,G.A[i].trongso);
		}
	}
	if(debug==2) 
	{
		int dau=3,duoi=4;
		printf("Dau %d: %d - Duoi %d: %d\n",dau,cap[dau],duoi,cap[duoi]);
		for(int i=0;i<G.n;i++) printf("%d ",ct[i]);
	}
}