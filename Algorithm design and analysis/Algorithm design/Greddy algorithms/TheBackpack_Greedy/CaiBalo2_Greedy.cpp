#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct
{
	char TenDV[20];
	float TL,GT,DG;
	int SL,PA;
} DoVat;

DoVat *ReadData(float *w,int *n)
{
	FILE *f;
	f=fopen("caibalo2.txt","r");
	fscanf(f,"%f",w);
	DoVat *dsdv;
	dsdv=(DoVat*)malloc(sizeof(DoVat));
	int i=0;
	while(!feof(f))
	{
		fscanf(f,"%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].TenDV);
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA=0;
		i++;
		dsdv=(DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x,DoVat *y)
{
	DoVat temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void bubbleSort(DoVat *dsdv, int n)
{
	for(int i=0;i<=n-2;i++)
		for(int j=n-1;j>i+1;j--)
		{
			if(dsdv[j].DG>dsdv[j-1].DG)
				swap(&dsdv[j],&dsdv[j-1]);
		}
}

void printSolv(DoVat *dsdv,int n,float w)
{
	float TongTL=0.0, TongGT=0.0;
	printf("\nPhuong an Cai Ba lo 2 dung thuat toan \"Greedy\" nhu sau:\n");
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
	printf("|STT|     Ten Do Vat     |T. Luong | Gia Tri |So luong | Don gia | Phuong an |\n");
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");
	for(int i=0;i<n;i++){
		printf("|%2d |%-20s|%9.2f|%9.2f|%5d    |%9.2f|%6d     |\n",
		i+1,dsdv[i].TenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].SL,dsdv[i].DG, dsdv[i].PA);
		TongTL=TongTL+dsdv[i].PA * dsdv[i].TL;
		TongGT=TongGT+dsdv[i].PA * dsdv[i].GT;
	}	
	printf("|---|--------------------|---------|---------|---------|---------|-----------|\n");	
	printf("Trong luong cua ba lo = %-9.2f\n",w);
	printf("Tong trong luong = %-9.2f\n",TongTL);
	printf("Tong gia tri = %-9.2f\n",TongGT);
}

void greedy(DoVat *dsdv,int n, float w)
{
	for(int i=0;i<n;i++)
	{
		dsdv[i].PA=(w/dsdv[i].TL);
		if(dsdv[i].PA>dsdv[i].SL) dsdv[i].PA=dsdv[i].SL;
		w=w-dsdv[i].PA*dsdv[i].TL;
	}
}

int main()
{
	int n;
	float w;
	DoVat *dsdv;
	
	dsdv=ReadData(&w,&n);
	bubbleSort(dsdv,n);
	greedy(dsdv,n,w);
	printSolv(dsdv,n,w);
	free(dsdv);
	return 0;
}
