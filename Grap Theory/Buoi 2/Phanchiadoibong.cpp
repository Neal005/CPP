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
void themcung(dothi *G, int x, int y)
{
    G->A[x][y]=1;
    G->A[y][x]=1;
    G->m++;
}
void duyetG1(dothi G, int *dd, int *p, int *mau, int *check, int x)
{
	if(dd[x]==0&&x<=G.n)
	{
		//printf("%d\n",x);
		dd[x]=1;
		for(int i=1;i<=G.n;i++)
		{
			if(G.A[x][i]==1) 
			{
				if(dd[i]==1&&mau[i]==mau[x]) *check=0;
				mau[i]=3-mau[x];
				if(dd[i]==0) p[i]=x;
				duyetG1(G,&(*dd),&(*p),&(*mau),&(*check),i);
			}
		}
	}
	else;
}
int phandoi(dothi G, int *dd, int *p, int *mau, int x)
{
	int i,dem,check=1;
	do
	{
		duyetG1(G,&(*dd),&(*p),&(*mau),&check,x);
		dem=0;
		for(i=1;i<=G.n;i++)
		{
			if(dd[i]==1) dem++;
			if(dd[i]==0) break;
		}
		if(dem<G.n) x=i;
	} while(dem<G.n);
	return check;
}
int main()
{
	dothi G;
	khoitaoG(&G);
    int m,n,u,v,dd[100],p[100],mau[100];
    for(int i=0;i<100;i++)
    {
        dd[i]=0;
    }
    for(int i=0;i<100;i++)
    {
    	p[i]=0;
	}
	for(int i=0;i<100;i++)
	{
		mau[i]=0;
	}
	mau[1]=1;
    scanf("%d%d",&n,&m);
    G.n=n;
    for(int i=0;i<m;i++)
    {
    	scanf("%d%d",&u,&v);
    	themcung(&G,u,v);
	}
    if(phandoi(G,dd,p,mau,1))
    {
    	for(int i=1;i<=n;i++)
    	{
    		if(mau[i]==mau[1]) printf("%d ",i);
		}
		printf("\n");
		for(int i=1;i<=n;i++)
    	{
    		if(mau[i]==3-mau[1]) printf("%d ",i);
		}
	}
	else printf("IMPOSSIBLE");
}