#include<stdio.h>
#include<windows.h>

#define debug 0

void readData(int *n)
{
	FILE *f;
	int temp;
	f=fopen("Thaynhot.neal","r");
	if(f==NULL&&debug) printf("Cant be open file!\n");
	else
	{
		fscanf(f,"%d",&temp);
		*n=temp;
	}
	fclose(f);
}

void saveData(int a)
{
	FILE *f;
	f=fopen("Thaynhot.neal","w");
	if(f==NULL&&debug) printf("Cant be Save!\n");
	else
	{
		fprintf(f,"%d",a);
	}
	fclose(f);
}

void interfaces()
{
	int n=0,a;
	char chose='0';
	do
	{
		printf("\t***Managing oil changes***\n\n");
		readData(&n);
		printf("                    _____\nLast changing oil: |%d|\n                   |_____|\n\n",n);
		printf("Enter the distance: ");
		scanf("%d",&a);
		if(a-n>=2000)
		{
			printf("\n*Time to changing oil!\n\n");
			saveData(a);
		}
		else
		{
			
			printf("\n*Dont need to changing oil yet!\n\n");
		}
		printf("Input another distance?\n\t1. Yes\t\t2. No\nchose: ");
		fflush(stdin); scanf("%c",&chose); fflush(stdin);
		if(chose=='1') system("cls");
	} while(chose!='2');
}

int main()
{
	interfaces();
	
	return 0;
}