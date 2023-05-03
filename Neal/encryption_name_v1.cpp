#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#define debug 0

void encryption(char a[])
{
	int i=0,dem=0,stop=1,start;
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
	printf(" |");
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