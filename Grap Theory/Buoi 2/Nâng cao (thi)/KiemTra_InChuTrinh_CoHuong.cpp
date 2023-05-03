#include<stdio.h>
#include<windows.h>
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
}
typedef struct
{
	int A[100][100];
	int soct;
} chutrinh;
void khoitaoCT(chutrinh *ct)
{
	ct->soct=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			ct->A[i][j]=0;
		}
	}
}
void themct(chutrinh *ct, int *p, int i, int x, int end)
{
	ct->A[ct->soct][0]++;
	ct->A[ct->soct][i]=x;
	if(x!=end) themct(&(*ct),&(*p),i+1,p[x],end);
	else;
}
void inct(chutrinh ct)
{
	printf("---> Do thi co %d chu trinh\n",ct.soct);
	for(int i=1;i<=ct.soct;i++)
	{
		printf("       Chu trinh so %d: ",i);
		for(int j=ct.A[i][0];j>0;j--)
		{
			       printf("%d ",ct.A[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------------------\n");
}
void duyetG1(dothi G, int *dd, int *p,chutrinh *ct, int *check, int x)
{
	if(dd[x]==0&&x<=G.n)
	{
		//printf("%d\n",x);
		dd[x]=1;
		for(int i=1;i<=G.n;i++)
		{
			if(G.A[x][i]==1&&dd[i]==1) 
			{
				*check=1;
				ct->soct++;
				themct(&(*ct),p,1,x,i);
			}
			if(G.A[x][i]==1) 
			{
				if(dd[i]==0) p[i]=x;
				duyetG1(G,&(*dd),&(*p),&(*ct),&(*check),i);
			}
		}
	}
	else;
}
int cochutrinh(dothi G, int *dd, int *p,chutrinh *ct,int x)
{
	int i,dem,check=0;
	do
	{
		duyetG1(G,&(*dd),&(*p),&(*ct),&check,x);
		dem=1;
		for(i=1;i<=G.n;i++)
		{
			if(dd[i]==1) dem++;
			if(dd[i]==0)
			{
			    dem=G.n+1;
			    break;
			}
		}
		if(dem<G.n) x=i;
	} while(dem<G.n);
	return check;
}
int main()
{
	dothi G;
	chutrinh ct;
	khoitaoCT(&ct);
	khoitaoG(&G);
	FILE *fp;
    int a,m,n,u,v,dd[100],p[100],check=0;
    for(int i=0;i<100;i++)
    {
        dd[i]=0;
    }
    for(int i=0;i<100;i++)
    {
    	p[i]=0;
	}
	do
	{
		if(check==1||check==0)
		{
			printf("Nhap do thi tu file hay nhap bang tay:\n1. Tu file     2. Nhap tay\nChon: ");
			scanf("%d",&a);
			khoitaoG(&G);
			khoitaoCT(&ct);
			for(int i=0;i<100;i++)
    		{
        		dd[i]=0;
    		}
    		for(int i=0;i<100;i++)
   			{
    			p[i]=0;
			}
			if(a==1) 
			{
				fp=fopen("Graph.txt","r");
			}
			if(a!=1)
			{
				printf("Nhap so dinh va so cung: ");
				scanf("%d%d",&n,&m);
				fflush(stdin);
			}
			if(a==1) fscanf(fp,"%d%d",&n,&m);
			fflush(stdin);
    		G.n=n;
    		G.m=m;
    		if(a!=1) printf("Nhap lan luot cac cung:\n");
    		for(int i=0;i<m;i++)
    		{
    			if(a==1) fscanf(fp,"%d%d",&u,&v);
    			if(a!=1) scanf("%d%d",&u,&v);
    			fflush(stdin);
   	 			themcung(&G,u,v);
			}
		}
//		if(check==1)
//		{
//			int temp;
//			for(int i=0;i<100;i++)
//    		{
//        		dd[i]=0;
//    		}
//    		for(int i=0;i<100;i++)
//    		{
//    			p[i]=0;
//			}
//			printf("Nhap so cung can them vao: "); scanf("%d",&temp);
//			printf("Nhap lan luot cac cung:\n");
//			for(int i=0;i<temp;i++)
//			{
//				scanf("%d%d",&u,&v);
//   	 			themcung(&G,u,v);
//   	 		}
//		}
//		if(check==2)
//		{
//			int temp,temp1;
//			for(int i=0;i<100;i++)
//    		{
//        		dd[i]=0;
//    		}
//    		for(int i=0;i<100;i++)
//    		{
//    			p[i]=0;
//			}
//			printf("Nhap so dinh can them: "); scanf("%d",&temp);
//			G.n+=temp;
//			n+=temp;
//			printf("Nhap cung: ");
//			scanf("%d",&temp1);
//			printf("Nhap lan luot cac cung:\n");
//			for(int i=0;i<temp;i++)
//			{
//				scanf("%d%d",&u,&v);
//   	 			themcung(&G,u,v);
//   	 		}
//		}
   		if(cochutrinh(G,dd,p,&ct,1))
		{
			inct(ct);
		}
    	else 
		{
			printf("---> DO THI KHONG CO CHU TRINH\n");
    		printf("------------------------------------------\n");
    	}
    	if(a==1) fclose(fp);
    	fflush(stdin);
		printf("\n\n**Tieptuc?\n1. nhap do thi moi     2. exit\nChon: ");
		scanf("%d",&check);
		fflush(stdin);
    	if(check==1) system("cls");
	} while(check==1);
//	printf("\nThoat sau 60s");
//	if(a=='1') Sleep(60000);
}