#include<stdio.h>
typedef struct
{
	int A[100];
	int dinh;
} nganxep;
void khoitaoS(nganxep *S)
{
	for(int i=0;i<100;i++)
	{
		S->A[i]=0;
	}
	S->dinh=0;
}
int lay(nganxep S)
{
	return S.A[S.dinh-1];
}
void them(nganxep *S, int x)
{
	S->A[S->dinh]=x;
	S->dinh++;
}
void xoa(nganxep *S)
{
	S->dinh--;
}
int dsrong(nganxep S)
{
	if(S.dinh==0) return 1;
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
    nganxep S;
    dothi G;
    khoitaoS(&S);
    khoitaoG(&G);
    scanf("%d%d",&n,&m);
    G.n=n;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        themcung(&G,u,v);
    }
    //duyet sau
    int dd[100];
    for(i=0;i<100;i++)
    {
        dd[i]=0;
    }
    them(&S,1);

    while(!dsrong(S))
    {
        int x=lay(S);
        xoa(&S);
        
        if(dd[x]==0) //chua duyet
        {
            printf("%d\n",x);
            dd[x]=1;
            
            for(i=1;i<=n;i++){
	            if(G.A[x][i]==1){
	                them(&S,i);
	            }
	        }
        }
        
        if (dsrong(S))
	        for(i=1;i<=n;i++) {
	            if(dd[i]==0){
	                them(&S,i);
	                break;
	            }
	        }
    }
}