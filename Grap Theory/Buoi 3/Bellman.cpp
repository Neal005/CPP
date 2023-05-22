#include<stdio.h>
typedef struct
{
    int u,v;
    int w;
}Cung;
typedef struct
{
    Cung cung[100];
    int m,n;
} dothi;
void khoitaoG(dothi *G,int n)
{
    G->n=n;
    G->m=0;
}
void themcung(dothi *G, int u, int v, int w)
{
    G->cung[G->m].u=u;
    G->cung[G->m].v=v;
    G->cung[G->m].w=w;
    G->m++;
}
int pi[100];
int p[100];
int Bellman(dothi *G, int x)
{
    int u,v,w;
    for(u=1;u<=G->n;u++) pi[u]=999999;
    pi[x]=0;
    p[x]=-1;
    for(int i=1;i<=G->n;i++)
    {
        for(int j=0;j<G->m;j++)
        {
            u=G->cung[j].u;
            v=G->cung[j].v;
            w=G->cung[j].w;
            if(pi[u]+w<pi[v])
            {
                pi[v]=pi[u]+w;
                p[v]=u;
            }
        }
    }
    int chutrinham=0;
    for(int i=0;i<G->m;i++)
    {
        int u=G->cung[i].u;
        int v=G->cung[i].v;
        int w=G->cung[i].w;
        if(pi[u]+w<pi[v])
        {
            chutrinham=1;
            break;
        }
    }
    return chutrinham;
}
int main()
{
    dothi G;
    int m,n,u,v,w;
    scanf("%d%d",&n,&m);
    khoitaoG(&G,n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        themcung(&G,u,v,w);
    }
    if(Bellman(&G,1)) printf("YES");
    else
    printf("NO");
}