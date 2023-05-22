#include<stdio.h>
#include<math.h>
typedef struct
{
    int A[1000];
    int dau;
    int duoi;
} hangdoi;
void khoitaoQ(hangdoi *Q)
{
    Q->dau=0;
    Q->duoi=0;
}
void them(hangdoi *Q, int x)
{
    Q->A[Q->duoi]=x;
    Q->duoi++;
}
void xoa(hangdoi *Q)
{
    Q->dau++;
}
int lay(hangdoi Q)
{
   return Q.A[Q.dau]; 
}
int dsrong(hangdoi Q)
{
    if(Q.A[Q.duoi]==Q.A[Q.dau]) return 1;
    return 0;
}
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
void themcung(dothi *G, int x, int y)
{
    G->A[x][y]=1;
    G->A[y][x]=1;
    G->m++;
}
int main()
{
    int m,n,u,v,i;
    hangdoi Q;
    dothi G;
    khoitaoQ(&Q);
    khoitaoG(&G);
    scanf("%d%d",&n,&m);
    G.n=n;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        themcung(&G,u,v);
    }
    //duyet rong
    int dd[100];
    for(i=0;i<100;i++)
    {
        dd[i]=0;
    }
    them(&Q,1);

    while(!dsrong(Q))
    {
        int x=lay(Q);
        xoa(&Q);
        
        if(dd[x]==0) //chua duyet
        {
            printf("%d\n",x);
            dd[x]=1;
            
            for(i=1;i<=n;i++){
	            if(G.A[x][i]==1){
	                them(&Q,i);
	            }
	        }
        }
        
        if (dsrong(Q))
	        for(i=1;i<=n;i++) {
	            if(dd[i]==0){
	                them(&Q,i);
	                break;
	            }
	        }
    }
}