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
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            G->A[i][j]=0;
        }
    }
}
void themcung(dothi *G, int x, int y,int a)
{
    G->A[x][y]=a;
    G->m++;
}
void MooreDijkstra(dothi *G,int *p,int *dd,int *pi, int x)
{
    int temp;
    p[x]=-1;
    pi[x]=0;
    for(int i=1;i<=G->n;i++)
    {
        int min=999999;
        for(int j=1;j<G->n;j++)
        {
            if(dd[j]==0&&pi[j]<min)
            {
                min=pi[j];
                temp=j;
            }
        }
        dd[temp]=1;
        for(int i=1;i<=G->n;i++)
        {
            if(G->A[temp][i]!=0&&dd[i]==0)
            {
                if(pi[temp]+G->A[temp][i]<pi[i])
                {
                    pi[i]=pi[temp]+G->A[temp][i];
                    p[i]=temp;
                }
            }
        }
    }
}
int main()
{
    dothi G;
    int m,n,u,v,a,pi[100],p[100],dd[100];
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
        pi[i]=999999;
    }
    khoitaoG(&G);
    scanf("%d%d",&n,&m);
    G.n=n;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&a);
        themcung(&G,u,v,a);
    }
    MooreDijkstra(&G,p,dd,pi,1);
//    int max=-1;
//    for(int i=1;i<=n;i++)
//    {
//    	if(pi[i]>max&&pi[i]!=999999) max=pi[i];
//	}
	if(pi[n]==999999) printf("-1");
    else printf("%d",pi[n]);
}