#include<stdio.h>
#define size 30
typedef struct
{
	float do_dai;
	int dau,cuoi;
	int da_dung;
} canh;

void readData(const char file_name[],canh a[][size],int *n)
{
	int i,j;
	FILE *f;
	f=fopen(file_name, "r");
	if (f==NULL){
		printf("Loi mo file!!!\n");
		return;
	}
	
	fscanf(f,"%d",n);
	
	for(i=0; i<*n; i++)
		for(j=0; j<*n; j++){
			fscanf(f,"%f",&a[i][j].do_dai); 
				a[i][j].dau=i;
				a[i][j].cuoi=j;
				a[i][j].da_dung=0;;
			}
	fclose(f);
}

void printMatrix(canh a[][size],int n)
{
	printf("\nMa tran \"Trong So\" cua do thi\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf(" %c%c=%5.2f",a[i][j].dau+97,a[i][j].cuoi+97,a[i][j].do_dai);
		printf("\n");
	}
}

void printSolv(canh PA[],int n)
{
	int i;
	float sum=0.0;
	printf("\nPHUONG AN TIM DUOC:\n");
	for(i=0; i<n; i++){
		sum+= PA[i].do_dai;
		printf(" Canh %c%c = %5.2f\n", PA[i].dau+97, PA[i].cuoi+97, PA[i].do_dai);
    }  
    printf("CHU TRINH : ");
	for(i=0; i<n; i++){
		printf("%c",PA[i].dau+97);
		printf("-> ");
    }  
	printf("%c",PA[0].dau+97);    
	printf("\nTong do dai cac canh cua chu trinh = %5.2f\n", sum);
}

float theMinestEdge(canh a[][size],int n)
{
	float Cmin=3.40282e+38;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j&&!a[i][j].da_dung&&a[i][j].do_dai<Cmin)
				Cmin=a[i][j].do_dai;
	return Cmin;
}

float can_duoi(canh a[][size],float TGT,int n,int i)
{
	return TGT+(n-i)*theMinestEdge(a,n);
}

void updateTheBestSolv(canh a[][size],int n,float TGT,float *GNNTT,canh x[],canh PA[])
{
	x[n-1]=a[x[n-2].cuoi][x[0].dau];
	TGT=TGT+x[n-1].do_dai;
	if(*GNNTT>TGT)
	{
		*GNNTT=TGT;
		for(int i=0;i<n;i++)
			PA[i]=x[i];
	}
}

int hasCycle(canh x[],int k,int ke_tiep)
{
	int i=0,co_CT=0;
	while(i<k&&!co_CT)
	{
		if(ke_tiep==x[i].dau) co_CT=1;
		else return co_CT;
	}
}

void brandNBound(canh a[][size],int n,int i,int dau,float *TGT,float *CD,float *GNNTT, canh x[],canh PA[])
{
	 
	 for(int j=0; j<n; j++) 	
		if (dau!=j && !a[dau][j].da_dung && !hasCycle(x,i,j))
		{
			*TGT = *TGT + a[dau][j].do_dai;
			*CD = can_duoi(a, *TGT, n, i+1);
			if(*CD < *GNNTT)
			{
		  		x[i] = a[dau][j];
		  		a[dau][j].da_dung=1;
		  		a[j][dau].da_dung=1;
		  	
			   	if(i==n-2)
				{ 
				updateTheBestSolv(a, n, *TGT, GNNTT, x, PA);
		    	}   	
			 	else
			 		brandNBound(a, n, i+1, j, TGT, CD, GNNTT, x, PA);
	 		}
			*TGT = *TGT - a[dau][j].do_dai;
			a[dau][j].da_dung=0;
		}
}

void reset(canh a[][size],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j].da_dung=0;
}

int main()
{
	canh a[size][size];
	int n;
	printf("\nPhuong an TSP dung thuat toan \"Nhanh Can\":\n");
	readData("TSP.txt",a,&n);
	canh PA[n];
	canh x[n];
	char tpxp,yn;
	while(1)
	{
		fflush(stdin);
		printMatrix(a,n);
		float TGT=0.0,CD=0.0,GNNTT=3.40282e+38;
		printf("\nXuat phat tu thanh pho: ");
		scanf("%c",&tpxp);
		brandNBound(a,n,0,tpxp-97,&TGT,&CD,&GNNTT,x,PA);
		printSolv(PA,n);
		fflush(stdin);
		printf("\nCoutinue Y/N?");
		scanf("%c",&yn);
		if(yn=='N'||yn=='n') break;
		reset(a,n);
	}
	return 0;
}
