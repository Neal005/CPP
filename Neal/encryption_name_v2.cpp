#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<windows.h>
#define debug 0

void waiting(char a[])
{
	int n=strlen(a)/5;
	system("cls");
	for(int i=1;i<=n;i++)
	{
		printf("Please wait");
		for(int j=1;j<=3;j++)
		{
			printf(".");
			sleep(1);
		}
		system("cls");
	}
}

void encryption(char a[])
{
	int i=0,dem=0,stop=1,start;
	if(!debug) printf("\t**PLEASE ENTER YOUR BEAUTIFUL NAME!**\n+note: please dont type 'enter' between each word and use ENG\n-->\t");
	if(!debug) printf("%s",a);
	printf("\nYour output encryption name: | ");
	while(i<=strlen(a)&&stop)
	{
		start=0;
		if(a[i+dem]!='\n' and a[i+dem]!=' ') printf("%c",toupper(a[i+dem]));
		else
		{
			dem=0;
			if(a[i+dem]!='\n' and a[i+dem]!=' ') printf("%c",toupper(a[i+dem]));
			else start=1;
		}
		while(a[i]!=' ')
		{
			i++;
		}
		while(a[i]==' ')
		{
			i++;
			if(a[i]=='\n') stop=0;
		}
		if(!start) dem++;
	}
	printf(" |\n");
	if(strcmp(strupr(a),"TRAN THU NGAN\n")==0) printf("* LUC YEU NGAN RAT NHIEU! *");
}

int main()
{
	fflush(stdin);
	char check;
	char a[200];
	do
	{
		printf("\t**PLEASE ENTER YOUR BEAUTIFUL NAME!**\n+note: please dont type 'enter' between each word and use ENG\n-->\t");
		fgets(a,sizeof(a),stdin);
		if(!debug) waiting(a);
		encryption(a);
		printf("\n_____________________________________________\n1. try another name\t2. exit\nchoose: ");
		fflush(stdin);
		scanf("%c",&check);
		fflush(stdin);
		if(check=='1')
		{
			system("cls");
		}
	} while(check=='1');
}