#include<stdio.h>
#define debug 0

//Ngan xep
typedef struct
{
	int A[100];
	int dinh;
} nganxep;

void khoitaoS(nganxep *S)
{
	S->dinh=0;
}

void them(nganxep *S,int x)
{
	S->A[S->dinh]=x;
	S->dinh++;
}

int lay(nganxep *S)
{
	S->dinh--;
	return S->A[S->dinh];
}

int rong(nganxep S)
{
	if(S.dinh==0) return 1;
	return 0;
}

int Cotrong(nganxep *S, int x)
{
	for(int i=0;i<S->dinh;i++)
		if(S->A[i]==x) return 1;
	return 0;
}

//Do thi
typedef struct
{
	int A[100][100];
	int n,m;
} dothi;

void KhoitaoG(dothi *G, int n)
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

void themcung(dothi *G, int u, int v)
{
	G->A[u][v]=1;
	G->m++;
}

//chi so
int dem,stpltm,tpltm[100][100],p[100],num[100],minnum[100],dd[100],so_pt[100];
void resetarray()
{
	stpltm=0;
	for(int i=0;i<100;i++)
	{
		p[i]=i;
		dd[i]=0;
		num[i]=0;
		minnum[i]=0;
		so_pt[i]=1;
		for(int j=0;j<100;j++)
		{
			tpltm[i][j]=0;
		}
	}
}

int Min(int a,int b)
{
	if(a<b) return a;
	return b;
}

//Duyet
void TPLTM(dothi *G, nganxep *S, int x)
{
	if(!dd[x])
	{
		them(S,x);
		dd[x]=1;
		dd[0]++;
		num[x]=dd[0];
		if(debug) printf("__________________________________\n*Duyet: %d\n*Slddd = %d\n*num[%d] = %d\n__________________________________\n",x,dd[0],x,num[x]);
		minnum[x]=num[x];
	}
	for(int i=1;i<=G->n;i++)
	{
		if(G->A[x][i])
		{
			if(!dd[i])
			{
				p[i]=x;
				TPLTM(G,S,i);
			}
			if(dd[i]&&Cotrong(S,i))
			{
				minnum[x]=Min(minnum[x],minnum[i]);
			}
		}
	}
	//Quay lui
	minnum[p[x]]=Min(minnum[x],minnum[p[x]]);
	if(debug) printf("__________________________________\n");
	if(debug) printf("Quay lui [%d]\n*num[%d] = %d\n*minnum[%d] = %d\n",x,x,num[x],x,minnum[x]);
	if(num[x]==minnum[x])
	{
		int temp;
		if(debug) printf("tpltm thu %d:\n",stpltm+1);
		do
		{
			temp=lay(S);
			if(debug) printf("Lay S ra: %d\n",temp);
			tpltm[stpltm][so_pt[stpltm]]=temp;
			if(debug) printf("tpltm[%d]: %d\n",tpltm[stpltm][0],tpltm[stpltm][so_pt[stpltm]]);
			tpltm[stpltm][0]++;
		} while(temp!=x);
		stpltm++;
		if(debug) printf("__________________________________\n");
	}
}

//Main
int main()
{
	int n,m,u,v;
	resetarray();
	dothi G;
	nganxep S;
	khoitaoS(&S);
	scanf("%d%d",&n,&m);
	KhoitaoG(&G,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		themcung(&G,u,v);
	}
	TPLTM(&G,&S,1);
	printf("%d",stpltm);
}