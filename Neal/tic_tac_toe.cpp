#include<stdio.h>
#include<windows.h>
#define debug 0
typedef struct
{
	int x,y;
} xel;

typedef struct
{
	xel A[9];
} Locate;

int table[3][3],win_player1=0,win_player2=0,win_AI=0;
Locate locate;

void init()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			table[i][j]=0;
	
	int count=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			locate.A[count].x=i;locate.A[count].y=j;
			count++;
		}
}

void init_xel(xel* x)
{
	x->x=x->y=-1;
}

void print_table()
{
	printf("\t***TIC TAC TOE***\n\n\t   ");
	printf("   |   |   \n\t   ");
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(table[j][i]==0)
			{
				printf(" %d ",i+1+3*j);
				if(i<2) printf("|");
			}
			if(table[j][i]==1)
			{
				printf(" X ");
				if(i<2) printf("|");
			}
			if(table[j][i]==2)
			{
				printf(" O ");
				if(i<2) printf("|");
			}
		}
		if(j<2) printf("\n\t  ____|___|____\n\t      |   |   \n\t   ");
	}
	printf("\n\t      |   |   \n");
}

void turn(int player)
{
	int stop;
	char numchar='0';
	int num=0;
	do
	{
		stop=1;
		if(player==1)printf("\n*Player X");
		else printf("\n*Player O");
		printf("\nChoose xel: "); fflush(stdin); scanf("%c",&numchar); fflush(stdin);
		if(numchar<'1'||numchar>'9')
		{
			system("cls");
			print_table();
			fflush(stdin);
			printf("Number is error!\n",numchar);
		}
		else
		{
			
			if(numchar=='1') num=1;if(numchar=='2') num=2;if(numchar=='3') num=3;if(numchar=='4') num=4;
			if(numchar=='5') num=5;if(numchar=='6') num=6;if(numchar=='7') num=7;if(numchar=='8') num=8;
			if(numchar=='9') num=9;
			
			if(table[locate.A[num-1].x][locate.A[num-1].y]!=0)
			{
				system("cls");
				print_table();
				fflush(stdin);
				printf("The xel is chosen! Please choose again!\n");
			}
			else stop=0;
		}
	} while(stop);
	if(table[locate.A[num-1].x][locate.A[num-1].y]==0)
	{
		table[locate.A[num-1].x][locate.A[num-1].y]=player;	
		system("cls");
		print_table();
		fflush(stdin);
	}
}

int main()
{
	init();
	xel x;
	init_xel(&x);
	print_table();
	int count=1,stop_count=1;
	do
	{
		for(int i=1;i<=2;i++)
		{
			turn(i);
			count++;
			if(count==10) break;
		}
		if(count>9) stop_count=0;
	} while(stop_count);
	if(count>9) printf("\n\t    *DRAWN!*");
}