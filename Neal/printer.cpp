//In so trang khi in 4 to trong mot mat A4

#include<stdio.h>
#include<math.h>
#include<windows.h>
#define debug 0

int sotrang;

void reset()
{
	sotrang=0;
}

void create_txt()
{
	FILE *fptr;
	fptr = fopen("printer.txt", "w");
	if(fptr == NULL)
	{
    	printf("Error!");
    	exit(1);
	}
	//
	fprintf(fptr,"So trang: %d\n\n",sotrang);
	if(sotrang/4==0)
	{
		fprintf(fptr,"\t*Chi co 1 mat do so trang < hoac = 1*\nNhap: ");
		for(int j=1;j<=sotrang;j+=8)
		{
			fprintf(fptr,"%d",j);
			if(j+3<=sotrang) fprintf(fptr,"-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {fprintf(fptr,"-%d",i1);break;}
			if(j+8<=sotrang) fprintf(fptr,",");
		}
	}
	else
	if(sotrang/4==1&&sotrang%4==0)
	{
		fprintf(fptr,"\t*Chi co 1 mat do so trang < hoac = 1*\nNhap: ");
		for(int j=1;j<=sotrang;j+=8)
		{
			fprintf(fptr,"%d",j);
			if(j+3<=sotrang) fprintf(fptr,"-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {fprintf(fptr,"-%d",i1);break;}
			if(j+8<=sotrang) fprintf(fptr,",");
		}
	}
	else
	{
		fprintf(fptr,"+ Mat truoc: ");
		for(int j=1;j<=sotrang;j+=8)
		{
			fprintf(fptr,"%d",j);
			if(j+3<=sotrang) fprintf(fptr,"-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {fprintf(fptr,"-%d",i1);break;}
			if(j+8<=sotrang) fprintf(fptr,",");
		}
		fprintf(fptr,"\n\n+ Mat sau: ");
		for(int j=5;j<=sotrang;j+=8)
		{
			fprintf(fptr,"%d",j);
			if(j+3<=sotrang) fprintf(fptr,"-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {fprintf(fptr,"-%d",i1);break;}
			if(j+8<=sotrang) fprintf(fptr,",");
		}
	}
	//
	fclose(fptr);
}

void print()
{
	if(debug) printf("So trang A4: %d\nSodu: %d\n",sotrang/4,sotrang%4);
	if(sotrang/4==0)
	{
		printf("\t*Chi co 1 mat do so trang < hoac = 1*\nNhap: ");
		for(int j=1;j<=sotrang;j+=8)
		{
			printf("%d",j);
			if(j+3<=sotrang) printf("-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {printf("-%d",i1);break;}
			if(j+8<=sotrang) printf(",");
		}
	}
	else
	if(sotrang/4==1&&sotrang%4==0)
	{
		printf("\t*Chi co 1 mat do so trang < hoac = 1*\nNhap: ");
		for(int j=1;j<=sotrang;j+=8)
		{
			printf("%d",j);
			if(j+3<=sotrang) printf("-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {printf("-%d",i1);break;}
			if(j+8<=sotrang) printf(",");
		}
	}
	else
	{
		printf("______________________________________________________________________\n\n");
		printf("+ Mat truoc: ");
		for(int j=1;j<=sotrang;j+=8)
		{
			printf("%d",j);
			if(j+3<=sotrang) printf("-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {printf("-%d",i1);break;}
			if(j+8<=sotrang) printf(",");
		}
		printf("\n\n+ Mat sau: ");
		for(int j=5;j<=sotrang;j+=8)
		{
			printf("%d",j);
			if(j+3<=sotrang) printf("-%d",j+3);
			if(j+3>sotrang&&(j+2<=sotrang||j+1<=sotrang)) for(int i1=sotrang;i1>=j;i1--) {printf("-%d",i1);break;}
			if(j+8<=sotrang) printf(",");
		}
	}
}

int main()
{
	char check='1';
	do
	{
		reset();
		printf("*Nhap so trang cua tai lieu: ");
		scanf("%d",&sotrang);
		print();
		printf("\n______________________________________________________________________\n1. Tiep tuc voi so trang khac\t  2. export file txt\t   t3. Exit\nChon: ");
		fflush(stdin);
		scanf("%c",&check);
		fflush(stdin);
		if(check=='2')
		do
		{
			create_txt();
			system("cls");
			printf("*Nhap so trang cua tai lieu: %d\n",sotrang);
			print();
			printf("\n______________________________________________________________________\n1. Tiep tuc voi so trang khac\t  2. export file txt\t   t3. Exit\nChon: ");
			fflush(stdin);
			scanf("%c",&check);
			fflush(stdin);
		} while(check=='2');
		if(check=='1') system("cls");
	} while(check=='1');
}